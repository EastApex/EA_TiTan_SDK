//
//  SCBluetoothCentral.h
//  SCBluetooth
//
//  Created by 李永彬 on 2020/12/8.

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "SCBluetoothCallback.h"
#import "SCBluetoothDevice.h"
#import "SCBluetoothError.h"
#import "SCBluetoothTaskManager.h"
#import "SC_ConnectionPool.h"
#import "SC_Scanner.h"
#import "SC_RestorePool.h"

@class SCBluetoothData;

#pragma mark - const
static const NSUInteger kToDoDisconnect = 1;
static const NSUInteger kToDoSearch = 2;
static const NSUInteger kToDoConnect = 3;
static const NSUInteger kToDoAutoConnect = 4;
static const NSUInteger kToDoOtaConnect = 5;



static const NSTimeInterval kDefaultConnectTimeout = 15;
static const NSTimeInterval kDefaultDisconnectTimeout = 15;

#pragma mark - notification
// 蓝牙状态改变时通知

// 蓝牙打开通知 [ble turned on notification]
extern NSString *SCBluetoothStatePoweredOnNotification;
// 蓝牙状态不可知通知 [ble state unknown notification]
extern NSString *SCBluetoothStateUnknowNotification;
// 蓝牙状态重置ing通知 [ble state reset notification]
extern NSString *SCBluetoothStateResettingNotification;
extern NSString *SCBluetoothStateUnsupportedNotification;
extern NSString *SCBluetoothStateUnauthorizedNotification;
extern NSString *SCBluetoothStatePoweredOffNotification;
// 蓝牙状态改变通知
extern NSString *SCBluetoothStateChangedNotification;

// 蓝牙设备正在自动连接的通知[ble is auto-connecting notification]
extern NSString *SCBluetoothStartAutoConnectingNotification;
// 蓝牙设备结束自动连接的通知[ble is end-connecting notification ]
extern NSString *SCBluetoothEndAutoConnectingNotification;
// 连接设备失败的通知[fail to connect with device notification]
extern NSString *SCBluetoothDidFailToConnectDeviceNotification;
// 设备已经连接上的通知[device connect with phone successfully notification]
extern NSString *SCBluetoothConnectedFromRestoreStateNotification;

extern NSString *SCBluetoothConnectedNotification;

extern NSString *SCBluetoothDisConnectedNotification;

#pragma mark - keys

extern NSString *SCKeyBluetoothConnectedDeviceName;
extern NSString *SCKeyBluetoothConnectedDeviceIdentify;
extern NSString *SCKeyBluetoothConnectedDeviceMacMap;
extern NSString *SCKeyBluetoothDeviceType;
extern NSString *SCKeyBluetoothDeviceID;
extern NSString *SCKeyBluetoothRestoreKey;

#pragma mark - enum

/*!
 蓝牙状态 [ble state]
 
 - SCBluetoothStateDisable: 蓝牙不可用
 - SCBluetoothStateAvailable: 蓝牙可用
 - SCBluetoothStateConnecting: 正在连接
 - SCBluetoothStateDisconnected: 断连了
 - SCBluetoothStateConnected: 已经连接上
 */
typedef NS_ENUM(NSInteger, SCBluetoothState) {
    SCBluetoothStateDisable,
    SCBluetoothStateAvailable,
    SCBluetoothStateConnecting,
    SCBluetoothStateDisconnected,
    SCBluetoothStateConnected
};

/**
 SCBluetoothStateDisable的具体原因
 */
typedef NS_ENUM(NSInteger, SCBLEDisableDetailState) {
    SCBLEDisableDetailStateUnkonwn,
    SCBLEDisableDetailStateUnsuported,
    SCBLEDisableDetailStateUnauthorized,
    SCBLEDisableDetailStatePowerOff
};

#pragma mark - class

/*!
 @class SCBluetoothCentral
 @classdesign 单例 [singleton]
 @brief 蓝牙管理中心 [ble management center]
 
 蓝牙SDK中心类，所有的功能入口中心 [ble management center class, All function entrance ]
 采用单例模式，请使用 [SCBluetoothCentral sharedInstance] 获取实例对象
 
 */
#pragma mark - todo task
typedef void(^SCBleTodoBlock)(void);

@interface SCBluetoothCentral : NSObject

/**
 连接设备的类
 */
@property (nonatomic, strong) SC_ConnectionPool *connectPool;

/**
 扫描设备的类
 */
@property (nonatomic, strong) SC_Scanner *scanner;

/**
 恢复连接设备的类
 */
@property (nonatomic, strong) SC_RestorePool *restorePool;

/**
 仅仅用于记录而已，不用管
 */
@property (nonatomic, strong) NSMutableSet *connectedPeripheralSets;

/**
 正在连接的OTA设备
 */
@property(nonatomic, strong) SCBluetoothDevice *toConnectOtaDevice;

/**
 正在链接的设备
 */
@property(nonatomic, strong) SCBluetoothDevice *toConnectDevice;

// 是否恢复连接
@property(nonatomic, assign) BOOL restoredState;

/*! @brief
 当前连接上的设备 [device name connected]
 */
@property(nonatomic, strong, readwrite) SCBluetoothDevice *connectedDevice;

/*! @brief
 标记蓝牙连接状态
 */
@property(nonatomic, assign) SCBluetoothState state;

/// 标记蓝牙是被关闭还是没有权限
@property(nonatomic, assign) SCBLEDisableDetailState detailState;

/**
 获取手机上已经连上的蓝牙设备
 
 @param serviceUUIDs 根据服务IDs
 @return 已经连接上的设备
 */
- (NSArray *) getPhoneConnectedDevices:(NSArray *)serviceUUIDs;

// 由于设备或者手机远离手环，造成蓝牙断链，是否需要每隔一段时间去自动连接
@property(nonatomic, assign) BOOL needToAutoConnectDevice;

/*! @brief
  OTA设备 [OTA device]
 */

@property(nonatomic, strong) SCBluetoothDevice *otaDevice;

/*!
 @brief 返回蓝牙管理中心单例 [return ble management center singleton]
 
 @return SCBluetoothCentral 实例
 */
+ (SCBluetoothCentral *)sharedInstance;

/**
 @brief 重新初始化ble management center singleton

 */
- (void) resetCenter;

#pragma mark - property

/*! @brief
 设置自动连接的设备名称 [set auto-connect device name]
 */
@property(nonatomic, copy) NSString *autoConnectDeviceName;

/*! @brief
 设置自动连接的设备名称 [set auto-connect device name]
 */
@property(nonatomic, copy) NSString *autoConnectDeviceMacMap;

/*! @brief
 上一次连接的设备名称 [device name of last connection]
 */
@property(nonatomic, copy, readonly) NSString *lastConnectedDeviceName;

/*! @brief
 上一次连接的设备的UDID标志
 有重名设备，因此在Restore中使用UDID来重连，
 但是如果换手机，外设的UDID会变化，所以该属性只适合在restorepool恢复重连时适用
 */
@property(nonatomic, copy, readonly) NSString *lastConnectedDeviceIdentify;

@property(nonatomic, copy, readonly) NSString *lastConnectedDeviceMacMap;

/*! @brief
 正在连接设备名称 [device name connecting]
 */
@property(nonatomic, copy) NSString *connectingDeviceName;

@property(nonatomic, copy) NSString *connectingDeviceMacMap;

@property(nonatomic, copy) NSString *otaDeviceName;
@property(nonatomic, copy) NSString *otaDeviceMacMap;
//已经OTA的文件 SCOTADataModel
@property(nonatomic, strong) NSMutableArray *sendedModels;

@property(nonatomic, copy) NSString *toConnectDeviceName;
@property(nonatomic, copy) NSString *toConnectDeviceMacMap;
@property(nonatomic, copy) NSString *toConnectDeviceUUIDString;

/**
 回调集合
 */
@property(nonatomic, strong) SCBluetoothCallback *bcCallback;

/**
 蓝牙中心 ble central manager
 */
@property(nonatomic, strong, readonly) CBCentralManager *manager;

@property(nonatomic, assign, readonly, getter=isOTAing) BOOL OTAing;

@property(nonatomic, assign, readonly, getter=isApollo3) BOOL apollo3;

@property(nonatomic, assign) BOOL autoConnectWhenOTAFailed;
@property(nonatomic, assign) BOOL autoConnectWhenOTASuccess;

#pragma mark - public methods

- (void) otaFinish;
- (void) otaFailed;

/// 断连设备
- (void)disconnetDevice;

/*!
 @brief 清除连接设备信息 [clear up device connection info]
 */
- (void) clearConnectionInfo;

/*!
 @brief 取消所有的蓝牙任务 [canncel all ble task]
 */
- (void) cancelAllBluetoothTasks;

/*!
 @brief 发送蓝牙请求，使用SDK时，内部使用
 
 @param dataModel 数据模型
 @param callback 回调
 @return 任务
 */
- (SCBluetoothTask *) sendRequest:(SCBluetoothData *)dataModel callback:(SCBCRequestCallback)callback;

/*!
 @brief 发送蓝牙请求，使用SDK时，内部使用
 
 @param dataModel 数据模型
 @param tenDatasCallback 收到10条数据后返回
 @param callback 回调
 @return 任务
 */
- (SCBluetoothTask *) sendRequest:(SCBluetoothData *)dataModel tenDatasCallback:(void(^)(SCBluetoothData *dataModel))tenDatasCallback callback:(SCBCRequestCallback)callback;

/*!
 @brief 手动停止当前任务，并指定发生什么错误
 一般不要自己去调用这个函数
 这个函数公开给蓝牙框架内部调用
 
 @param errorCode 错误码
 @see SCBCCodeBLEDisconnected
 @see SCBCCodeRequestTimeout
 @see SCBCCodeConnectTimeout
 */
- (void) stopCurrentTaskWithErrorCode:(SCBCCode)errorCode;

/*!
 @brief 添加到todo
 */
- (void) addToDo:(NSUInteger)cmd block:(SCBleTodoBlock)block;

/*!
 @brief 从todo中移除
 */
- (void) removeTodo:(NSUInteger)cmd;

#pragma mark - 错误码处理
- (void) setHandler:(void(^)(SCBluetoothData *dataModel))handler
       forErrorCode:(SCBCCode)errorCode;
- (void) clearErrorCodeHandlers;

@end
