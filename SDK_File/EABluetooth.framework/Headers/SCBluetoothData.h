//
//  SCBluetoothData.h
//  SCBluetooth
//
//  Created by 李永彬 on 2020/12/8.

#import <Foundation/Foundation.h>
#import "Scpro.pbobjc.h"

/**
 蓝牙信息交互通道
 
 - SCBlueToothdataTypeNormal: 1001
 - SCBlueToothdataTypeMedia:1002
 - SCBlueToothdataTypeAddressBook: 1003
 - SCBlueToothdataTypeExpand: 1004
 */
typedef NS_ENUM(NSInteger, SCBlueToothdataType)
{
    SCBlueToothdataTypeNormal,
    SCBlueToothdataTypeMedia,
    SCBlueToothdataTypeAddressBook,
    SCBlueToothdataTypeExpand
};

typedef NS_ENUM(NSInteger, SCBluetoothDataState)
{
    SCBluetoothDataStatePlain,
    SCBluetoothDataStateSending,
    SCBluetoothDataStateSent,
    SCBluetoothDataStateSendFailed,
    SCBluetoothDataStateReciving,
    SCBluetoothDataStateRecived,
    SCBluetoothDataStateReciveFailed,
    SCBluetoothDataStateTimeout,
    SCBluetoothDataStateMultipleDataRecivedCount, //收到多条数据，个数的回应
    SCBluetoothDataStateRecivedTenDataCount
};

@protocol SCBluetoothDataDelegate<NSObject>
// 需要刷新超时时间
- (void) bluetoothDataNeedRefreshTimeout;

@end


@interface SCBluetoothData : NSObject

@property(nonatomic, weak) id<SCBluetoothDataDelegate> delegate;

+ (SCBluetoothData *) dataWithSendData:(NSData *)sendData
                               timeout:(NSTimeInterval)timeout
                                  type:(SCBlueToothdataType)type;

+ (SCBluetoothData *) dataWithSendData:(NSData *)sendData
                                  type:(SCBlueToothdataType)type;

- (SCBluetoothData *) initWithSendData:(NSData *)sendData
                               timeout:(NSTimeInterval)timeout
                                  type:(SCBlueToothdataType)type;

- (SCBluetoothData *) initWithSendData:(NSData *)sendData
                                  type:(SCBlueToothdataType)type;

/**
 发送数据
 */
@property(nonatomic, strong) NSData *sendData;

/**
 超时时间，默认20s
 */
@property(nonatomic, assign) NSTimeInterval timeout;

/**
 数据类型
 */
@property(nonatomic, assign) SCBlueToothdataType type;

/**
 数据发送接收的状态
 */
@property(nonatomic, assign) SCBluetoothDataState state;

/**
 出错原因
 */
@property(nonatomic, strong) NSError *error;

/**
 取消发送标志
 */
@property(nonatomic, assign, getter=isCancelSend) BOOL cancelSend;

/**
 查询命令的数据，如果返回数据是1条，数据是datas；
 如果返回数据是2条或更多
 */
@property(nonatomic, strong) NSData *receiveData;
@property(nonatomic, strong) NSArray *receiveDatas;
//获取到10条数据
@property(nonatomic, strong) NSMutableArray *receivedTenDatas;
//多少条数据回传一次（默认10条）
@property(nonatomic, assign) NSInteger postbackCount;
//以数组形式返回数据
@property(nonatomic, assign) BOOL returnDatas;
@property(nonatomic, assign) NSUInteger receiveDataLength;
// 默认是只返回一条的
@property(nonatomic, assign) NSUInteger receiveDataCount;
@property(nonatomic, assign) SCPT_Code responseCode;

/**
 设置命令的结果
 */
@property(nonatomic, assign) BOOL excuteCMDFlag;
@property(nonatomic, assign) NSInteger errorCode;

/**
 发送失败，重试次数，默认1次
 */
@property(nonatomic, assign) NSUInteger failedRetryCount;

- (void) refreshTimeout;

@end
