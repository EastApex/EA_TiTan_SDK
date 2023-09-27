//
//  SC_Scanner.h
//  SCBluetoothSDK
//
//  Created by 李永彬 on 2020/12/14.
//

#import <Foundation/Foundation.h>
#import "SCBluetoothCallback.h"
#import <CoreBluetooth/CoreBluetooth.h>
#import "SCBluetoothConfig.h"
#import "SC_CBCentralManagerDelegateProxy.h"

NS_ASSUME_NONNULL_BEGIN

@interface SC_Scanner : NSObject<SC_CBCentralManagerDiscoveryDelegate>

/**
 蓝牙扫描和链接相关配置项
 */
@property(nonatomic, strong) SCBluetoothConfig *config;

/**
 @brief 蓝牙搜索设备 [search device]
 
 @param callback callback
 */
- (void) scanDevicesWithCallback:(SCBCSearchDevicesBlock)callback;

/*!
 @brief 停止搜索设备 [stop search device]
 */
- (void) stopScanDevices;

/*!
 @brief 蓝牙搜索设备，几秒之后自动停止搜索 [ble will search device, but it will stop after a few seconds]
 
 @param progressHandler 每次搜索到设备都会回调 [there is a callback everytime ble searchs]
 @param duration 多少秒之后自动停止搜索，如果是0，则不会自动停止 [after how many seconds auto-search should stop, if set 0, it will never stop]
 @param completionHandler 自动停止后，回调 [callback when stop search]
 */
- (void)scanDevicesWithProgressHandler:(SCBCSearchDevicesBlock)progressHandler
                              duration:(NSTimeInterval)duration
                      completionHandler:(SCBCStopSearchingDevicesBlock)completionHandler;

/*
 移除搜索定时器
 */
- (void) removeSearchTimer;

@end

NS_ASSUME_NONNULL_END
