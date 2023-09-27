/*!
 @header SCBluetoothError.h
 
 @author liyongbin on 2020/12/08.
 @copyright  2020年 smartcomm. All rights reserved.
 */
#ifndef SCBluetoothError_h
#define SCBluetoothError_h

#import <Foundation/Foundation.h>

static NSString *const SCConnectionErrorDomain = @"SCConnectionErrorDomain";
static NSString *const SCSearchDevicesErrorDomain = @"SCSearchDevicesErrorDomain";
static NSString *const SCDisconnectDeviceErrorDomain = @"SCDisconnectDeviceErrorDomain";
static NSString *const SCDataErrorDomain = @"SCDataErrorDomain";
static NSString *const SCRequestErrorDomain = @"SCRequestErrorDomain";
static NSString *const SCDeviceErrorDomain = @"SCDeviceErrorDomain";
static NSString *const SCDataCodeErrorDomain = @"SCDataCodeErrorDomain";

#pragma mark - CODE

/*!
 蓝牙SDK错误码
 
 - SCBCCodeBLEUnavailable: 蓝牙不可用
 - SCBCCodeRequestTimeout: 蓝牙任务超时
 - SCBCCodeRequestFailed: 蓝牙任务请求失败
 - SCBCCodeConnectTimeout: 连接超时
 - SCBCCodeSearchTimeout: 搜索超时
 - SCBCCodeDisconnectTimeout: 断连超时
 - SCBCCodeConnectInexistentDevice: 连接不存在的设备
 - SCBCCodeDataFormatError: 设备回传数据解析错误
 - SCBCCodeParamsError: 请求参数错误
 - SCBCCodePowerLowError: 设备电量过低错误
 - SCBCCodeDeviceUnsuport: 设备不支持
 - SCBCCodeOtaError: ota出错
 */
typedef NS_ENUM(NSInteger, SCBCCode)
{
    SCBCCodeBLEUnavailable = 9,      // 设备不可用，蓝牙未打开
    SCBCCodeBLEDisconnected = 13,
    SCBCCodeBLEConnecting = 12,   // 正在连接
    SCBCCodeBLEException = 11,      // 蓝牙异常，手机系统bug，导致无法扫描出外设服务和特征
    SCBCCodeRequestTimeout = 14,
    SCBCCodeRequestFailed = 15,
    SCBCCodeConnectTimeout = 20,
    SCBCCodeSearchTimeout = 21,
    SCBCCodeDisconnectTimeout = 22,
    SCBCCodeConnectInexistentDevice = 27,
    SCBCCodeConnectRepeat = 28,
    SCBCCodeConnectOverrided = 29,
    SCBCCodeDataFormatError = 30,
    SCBCCodeParamsError = 31,
    SCBCCodeTaskCancelError = 32,
    SCBCCodePowerLowError = 60,
    SCBCCodeDeviceUnsuport = 256,
    SCBCCodeOtaError = 90,
    SCBCCodeRequestOverrided = 100,  // 请求被覆盖
    SCBCCodeOtaDataInvalidError = 101, //固件无效
    SCBCCodeOtaForbiddenError = 102, //固件无效
    SCBCCodeWorkoutRunningError = 103, //正在进行workout
    /** 提醒时间冲突 */
    SCBCCodeRemindTimErr = 104,
    /** 提醒周期冲突 */
    SCBCCodeRemindCycErr = 105,
    /** 提醒数量超过最大允许 */
    SCBCCodeRemindMaxErr = 106,
    /** 提醒ID错误 */
    SCBCCodeRemindIdErr = 107
};

#endif /* SCBluetoothCMDDefine_h */
