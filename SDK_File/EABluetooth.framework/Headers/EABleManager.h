//
//  EABleManager.h
//  Template
//
//  Created by Aye on 2021/3/15.
//  version: 2022.12.06 

/**

 Demo & SDK
 https://github.com/EastApex/EASDKTool_iOS.git
 
 SDK access documentation
 https://www.showdoc.com.cn/2042713679210858/0
 
 Date：2023-11-03
 Version：1.0.83.4
 
 1.fixed sleep data bug.

  */

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "EAPeripheralModel.h"
#import "EABleConfig.h"
#import <EABluetooth/EAEnum.h>
#import <EABluetooth/OPQCommon.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN






#define kKeychainService                    @"com.eastapex.bluetooth"
#define kKeychainDataAccount                @"data_apexwear"


@protocol EABleManagerDelegate <NSObject>


/// Scanning Discovered watch (in real time)
/// 扫描发现的设备 （实时）
/// @param peripheralModel peripheral 设备
- (void)didDiscoverPeripheral:(EAPeripheralModel *)peripheralModel;

@end

/// Bluetooth data Broker
/// 蓝牙数据代理
@protocol EABleManagerDataDelegate <NSObject>

/// Bluetooth data 蓝牙数据
/// @param characteristic characteristic 通道
/// @param error error 错误信息
- (void)updateValueForCharacteristic:(CBCharacteristic *)characteristic error:(NSError *)error;

@end





/// Bluetooth data
/// 蓝牙数据
typedef void(^UpdateValueBlock)(CBCharacteristic *characteristic,NSError *error);

@interface EABleManager : NSObject

/// The bluetooth Settings
/// 蓝牙设置
@property (nonatomic,strong) EABleConfig *bleConfig;

/// Searching for watch Agents
/// 搜索设备代理
@property(nonatomic,assign) id<EABleManagerDelegate> delegate;

/// ignore：Bluetooth data Broker
/// 忽略：蓝牙数据代理
@property(nonatomic,weak) id<EABleManagerDataDelegate> dataDelegate;

/// Watch connection status
/// 连接设备状态
@property(nonatomic,assign) EAConnectStateType connectState;

/// 当前连接的设备
/// Currently connected device
@property (nonatomic, strong) EAPeripheralModel *eaPeripheralModel;

/// 蓝牙状态
/// Bluetooth status
@property(nonatomic,assign) EABleState bleState;

/// The singleton
/// 单例
+ (instancetype)defaultManager;

/// 【EA & SC】scan watch
- (void)scanPeripherals;

/// 【EA & SC】stop scan watch
- (void)stopScanPeripherals;

/// 【EA & SC】watch connect func
/// - Parameters:
///   - peripheralName: peripheral name
///   - sn: Class EAPeripheralModel.SN
- (void)connectPeripheralName:(NSString *)peripheralName sn:(NSString *)sn;

/// 【EA & SC】connect watch
- (void)connectToPeripheral:(EAPeripheralModel *)peripheralModel;


/// 【EA & SC】Disconnect the watch. Restart the App, EASDK will not automatically connect to the watch.
- (void)disconnectAndNotReConnectPeripheral;

/// 【EA & SC】Disconnect from the watch and reset and clear the watch data.
- (void)unbindAndResetPeripheral;

/// 【EA & SC】Check whether the watch is connected
- (BOOL)isConnected;

/// 【EA & SC】Check whether to enable Bluetooth
- (BOOL)isBleOn;


#pragma mark - Equipment related Methods 设备相关方法




/// reconnection
/// 重连设备
- (void)reConnectToPeripheral;

/// reconnection（Need the SN number or mac address of the watch）
/// 重连设备（传手表的SN号或者mac address）
- (void)reConnectToPeripheral:(NSString *)sn;

/// reconnection（Need the uuidString of the watch）
/// 重连设备（传手表的uuidString）
- (void)reConnectToPeripheralWithUUIDString:(NSString *)uuidString;

/// Cancel connection
/// 取消连接（连接时可用）
- (void)cancelConnectingPeripheral;

/// Disconnect the watch. Restart the App, and EASDK will automatically connect the watch.
/// 断开手表连接。重启App，EASDK自动连接。
- (void)disconnectPeripheral;


/// Disconnect the watch. Restart the App, EASDK will not automatically connect to the watch.
/// 断开手表连接。重启App，EASDK不会自动连接。
- (void)unbindPeripheral DEPRECATED_MSG_ATTRIBUTE("Please use \"disconnectAndNotReConnectPeripheral\"");



/// Gets the connected watch
/// 获取连接的设备信息
- (EAPeripheralModel *)getPeripheralModel;

#pragma mark 分析广播包
- (EAPeripheralModel *)analyseAdvertisementData:(NSDictionary *)advertisementData peripheral:(CBPeripheral *)peripheral  RSSI:( NSNumber *)RSSI;

/// ignore：
- (void)writeValue:(NSData *)Data forCharacteristic:(EACharacteristicType )characteristicType;

- (BOOL)isScanning;


@end

NS_ASSUME_NONNULL_END
