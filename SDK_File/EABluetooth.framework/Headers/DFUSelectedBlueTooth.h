//
//  DFUSelectedBlueTooth.h
//  dfuOfMine
//
//  Created by Apple on 16/1/19.
//  Copyright © 2016年 iOSLearing. All rights reserved.
//  空中升级工具类

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "DFUAirUpgradeMessageInfo.h"
typedef void (^ SuccessDFU)(DFUMessageTips messageTips,NSString *message);
typedef void (^ SuccessDFUArrayCallBack)(NSArray *arrayTypes);
typedef void (^ FailedDFU) (DFUMessageTips messageTips,NSString *message);

@interface DFUSelectedBlueTooth : NSObject
@property (nonatomic, assign) BOOL      isOTAing;
@property (nonatomic, assign) BOOL      isConnected;
/**
 *  初始化 DFUSelectedBlueTooth 单例
 *
 *  @return 蓝牙工具实例对象
 */
+ (instancetype)shareInstance;

- (void)startSearchPreipheral:(NSArray *)types success:(SuccessDFUArrayCallBack)success failed:(FailedDFU)failed;
/**
 *  通过服务名称和设备名称连接蓝牙设备
 *
 *
 *  @param preipheralName 蓝牙设备名字
 */
- (void)startSearchPreipheralName:(NSString *)preipheralName success:(SuccessDFU)success failed:(FailedDFU)failed;

- (void)send06;

/**
 *  空中升级
 *
 *  @param dataNordicBat    nodicDat文件
 *  @param dataNordicBin    nodicBin文件
 *  @param dataFreescaleBin 飞思卡尔文件
 *  @param dataTouchBin     触摸文件
 *  @param wordStockData    字库文件
 *  @param heartRateDate    心率文件
 *  @param wordDynamic      动态字库
 *  @param success          成功回调
 *  @param failed           失败回调
 */
- (void)sendDataForUpgrade:(NSData *)dataNordicBat dataBin:(NSData *)dataNordicBin dataFreescaleBin:(NSData *)dataFreescaleBin dataTouchBin:(NSData *)dataTouchBin wordStockData:(NSData *)wordStockData heartRateDate:(NSData *)heartRateDate wordDynamic:(NSData *)wordDynamic success:(SuccessDFU)success failed:(FailedDFU)failed;
+ (void)clearOtaInstance;
- (void)stopSearch;
@property (nonatomic, assign) BOOL isOTASuccess;
@property (nonatomic, assign) NSInteger allDataLength;

@end

typedef NS_ENUM(NSInteger,APPSUpgradeMCUType) {
    APPSUpgradeMCUTypeTouch,
    APPSUpgradeMCUTypeHeart,
    APPSUpgradeMCUTypePic,
    APPSUpgradeMCUTypeWord,
    APPSUpgradeMCUTypeFre,
    APPSUpgradeMCUTypeNordic
};
@interface DFUUpgradeToolModels : NSObject

@property (nonatomic, strong) NSData             *sendData;
@property (nonatomic, strong) NSData             *sendCrcData;
@property (nonatomic, strong) NSData             *sendAddData;
@property (nonatomic, strong) NSData             *orderData;
@property (nonatomic, assign) APPSUpgradeMCUType mcuType;
@property (nonatomic, assign) NSInteger          sendUpLength;
@property (nonatomic, assign) NSInteger          allLength;
+ (instancetype)upgradeToolModelsFrom:(NSData *)data crcData:(NSData *)crcData mcuType:(APPSUpgradeMCUType)mcuType sendUpLength:(NSInteger)sendUpLength allLength:(NSInteger)allLength;
@end
