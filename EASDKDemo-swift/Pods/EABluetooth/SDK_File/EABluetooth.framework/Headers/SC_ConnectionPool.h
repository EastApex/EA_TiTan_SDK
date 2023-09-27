//
//  SC_ConnectionPool.h
//  SCBluetoothSDK
//
//  Created by 李永彬 on 2020/12/15.
//

#import <Foundation/Foundation.h>
#import "SCBluetoothConfig.h"
#import "SCBluetoothDevice.h"
#import "SC_CBCentralManagerDelegateProxy.h"

NS_ASSUME_NONNULL_BEGIN

@interface SC_ConnectionPool : NSObject<SC_CBCentralManagerConnectionDelegate>

#pragma mark - property

/**
 蓝牙扫描和链接相关配置项
 */
@property(nonatomic, strong) SCBluetoothConfig *config;

/*!
 @brief 根据名称连接设备 [connect device]
 
 @param deviceName 设备名称
 @param callback 回调
 */
- (void) connectPeripheralWithName:(NSString *)deviceName deviceMacMap:(NSString *)deviceMacMap callback:(SCBCConnectDeviceBlock)callback;

/*!
 @brief 根据设备名称连接设备
 
 @param deviceName 设备名称
 @param timeout 连接超时时间
 @param callback 回调
 */
- (void) connectPeripheralWithName:(NSString *)deviceName deviceMacMap:(NSString *)deviceMacMap timeout:(NSTimeInterval)timeout callback:(SCBCConnectDeviceBlock)callback;

/*!
 @brief 连接设备 [connect device]
 @discussion 这里连接设备，应该是传入的搜索蓝牙设备接口搜索得到的设备。你也可以调用其他方法，只需要传入设备名称就可以进行连接 [regarding connect device , you should input device name searched by ble searching api(scanDevicesWithCallback) as parameter.You could also call other functions(connectDeviceName), what you need to do is just input device name, it should connect ]
 @see searchDevicesWithCallback:autoStopSearchingAfter:callback:
 @see connectDeviceName:callback:
 
 @param device 设备对象
 @param callback 回调
 */
- (void) connectPeripheral:(SCBluetoothDevice *)device callback:(SCBCConnectDeviceBlock)callback;

/*!
 @brief 连接设备
 
 @param device 设备对象
 @param timeout 超时时间
 @param callback 回调
 */
- (void) connectPeripheral:(SCBluetoothDevice *)device timeout:(NSTimeInterval)timeout callback:(SCBCConnectDeviceBlock)callback;

/*!
 直接开始连接设备
 */
- (void) doConnectPeripheral:(SCBluetoothDevice *)device callback:(SCBCConnectDeviceBlock)callback;

/*!
 @brief 此方法，只对制作OTA工具使用。
 
 @param deviceName 设备名称
 @param callback 回调
 */
- (void) connectOTAPeripheralName:(NSString *)deviceName deviceMacMap:(NSString *)deviceMacMap callback:(SCBCConnectDeviceBlock)callback;

- (void) connectOTAPeripheralName:(NSString *)deviceName deviceMacMap:(NSString *)deviceMacMap timeout:(NSTimeInterval)timeout callback:(SCBCConnectDeviceBlock)callback;

- (void) doConnectOtaPeripheral:(SCBluetoothDevice *)device callback:(SCBCConnectDeviceBlock)callback;

/*!
 @brief 断连设备 [disconnect with device]
 
 @param callback 回调
 */
- (void) disconnectWithCallback:(SCBCConnectDeviceBlock)callback;

/*!
 @brief 断连设备[disconnect with device]
 
 @param timeout 超时时间
 @param callback 回调
 */
- (void) disconnectWithTimeout:(NSTimeInterval)timeout callback:(SCBCConnectDeviceBlock)callback;

//移除连接设备定时器
- (void) removeConnectTimer;

//移除断连定时器
- (void) removeDisconnectTimer;

@end

NS_ASSUME_NONNULL_END
