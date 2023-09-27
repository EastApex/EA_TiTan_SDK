//
//  SCBluetoothTaskManager.h
//  SCBluetooth
//
//  Created by 李永彬 on 2020/12/8.
//

#import <Foundation/Foundation.h>
#import "SCBluetoothCallback.h"

@class SCBluetoothData;
@class SCBluetoothDevice;


typedef NS_ENUM(NSInteger, SCBluetoothTaskState)
{
    SCBluetoothTaskStateNew,
    SCBluetoothTaskStateExcuting,
    SCBluetoothTaskStateFailed,
    SCBluetoothTaskStateTimeout,
    SCBluetoothTaskStateSuccess,
    SCBluetoothTaskStateCancel
};

typedef NS_ENUM(NSInteger, SCBluetoothTaskType)
{
    SCBluetoothTaskTypeData,
    SCBluetoothTaskTypeResponse,
    SCBluetoothTaskTypeAddressBook
};

typedef void(^SCTaskErrorHandler)(SCBluetoothData *dataModel);

#pragma mark - task
@class SCBluetoothTask;

@protocol SCBluetoothTaskDelegate<NSObject>

- (void) taskFailedAndRequestRetry:(SCBluetoothTask *)task;

@end

@interface SCBluetoothTask : NSObject

// 这里可以覆盖dataModel的timeout
@property(nonatomic, assign) NSTimeInterval timeout;
@property(nonatomic, assign) SCBluetoothTaskType type;
@property(nonatomic, weak) id<SCBluetoothTaskDelegate> delegate;
@property(nonatomic, assign) SCBluetoothTaskState state;
@property(nonatomic, strong) NSError *error;

@property(nonatomic, strong) SCBluetoothData *subDataModel;

@property(nonatomic, strong) SCBluetoothData *dataModel;
@property(nonatomic, strong) SCBluetoothDevice *sendDevice;
@property(nonatomic, copy) SCBCRequestCallback callback;
@property(nonatomic, copy) void(^tenDatasCallback)(SCBluetoothData *dataModel);

- (SCBluetoothTask *) initWithDataModel:(SCBluetoothData *)dataModel
                             sendDevice:(SCBluetoothDevice *)sendDevice
                       tenDatasCallback:(void(^)(SCBluetoothData *dataModel))tenDatasCallback
                               callback:(SCBCRequestCallback)callback;

- (SCBluetoothTask *) initWithDataModel:(SCBluetoothData *)dataModel
                             sendDevice:(SCBluetoothDevice *)sendDevice
                               callback:(SCBCRequestCallback)callback;

/**
 这个不需要自己调用的，框架调用
 */
- (void) start;


/**
 这个可以自己调用取消任务
 */
- (void) cancel;

@end

#pragma mark - dataTask
@interface SCBluetoothDataTask : SCBluetoothTask

+ (SCBluetoothDataTask *)taskWithDataModel:(SCBluetoothData *)dataModel
                                sendDevice:(SCBluetoothDevice *)sendDevice
                          tenDatasCallback:(void(^)(SCBluetoothData *dataModel))tenDatasCallback
                                  callback:(SCBCRequestCallback)callback;

+ (SCBluetoothDataTask *)taskWithDataModel:(SCBluetoothData *)dataModel
                                sendDevice:(SCBluetoothDevice *)sendDevice
                                  callback:(SCBCRequestCallback)callback;

- (SCBluetoothDataTask *) initWithDataModel:(SCBluetoothData *)dataModel
                                 sendDevice:(SCBluetoothDevice *)sendDevice
                                   callback:(SCBCRequestCallback)callback;

@end

#pragma mark - mediaTask
@interface SCBluetoothResponseTask : SCBluetoothTask

+ (SCBluetoothResponseTask *)taskWithDataModel:(SCBluetoothData *)dataModel
                                    sendDevice:(SCBluetoothDevice *)sendDevice
                                      callback:(SCBCRequestCallback)callback;

- (SCBluetoothResponseTask *) initWithDataModel:(SCBluetoothData *)dataModel
                                     sendDevice:(SCBluetoothDevice *)sendDevice
                                       callback:(SCBCRequestCallback)callback;

@end

@interface SCBluetoothAddressBookTask : SCBluetoothTask

+ (SCBluetoothAddressBookTask *)taskWithDataModel:(SCBluetoothData *)dataModel
                                       sendDevice:(SCBluetoothDevice *)sendDevice
                                         callback:(SCBCRequestCallback)callback;

- (SCBluetoothAddressBookTask *) initWithDataModel:(SCBluetoothData *)dataModel
                                        sendDevice:(SCBluetoothDevice *)sendDevice
                                          callback:(SCBCRequestCallback)callback;

@end



#pragma mark - task manager

@protocol SCBluetoothTaskManagerDelegate <NSObject>

- (void) taskManagerRequestReconnect;

@end


@interface SCBluetoothTaskManager : NSObject

@property(nonatomic, weak) id<SCBluetoothTaskManagerDelegate> delegate;

- (void) clean;

- (void) addTask:(SCBluetoothTask *)task;
- (void) beginTask;

- (void) removeTask:(SCBluetoothTask *)task;
- (void) removeAllTask;
- (void) removeAllTaskOfType:(SCBluetoothTaskType)type;
- (void) removeTaskByCMD:(Byte)cmd;
- (void) removeTaskBySendData:(NSData *)sendData;

- (void) updateSendDevice:(SCBluetoothDevice *)device;

- (void) handBlePowerOff;

/**
 获取任务列表
 
 @return 任务列表
 */
- (NSArray *) getDataTaskList;
- (NSArray *) getResponseTaskList;

#pragma mark - 错误码处理
- (void) setHandler:(SCTaskErrorHandler)handler
       forErrorCode:(NSUInteger)errorCode;
- (void) clearErrorCodeHandlers;


@end
