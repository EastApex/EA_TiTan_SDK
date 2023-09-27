//
//  SCBluetoothCentral+notification.h
//  SmartcommWatch
//
//  Created by 李永彬 on 2021/3/27.
//

#import "SCBluetoothCentral.h"

NS_ASSUME_NONNULL_BEGIN

//@class SCNotificationModel;

@interface SCBluetoothCentral (notification)

/// 设置通知总开关的状态
/// @param state 状态值
/// @param callback callback description
- (SCBluetoothTask *)setNotificationMainSwitchState:(BOOL)state callback:(SCBCBoolCallback)callback;

/// 获取所有类型通知的开关状态
/// @param callback callback description
- (SCBluetoothTask *)getNotificationSwitchStateWithCallback:(void(^)(NSArray<SCPT_NotificationSwitches_Config *> *models, NSError *error))callback;

/// 设置某个通知 的开关状态
/// @param notificationModels 通知数组
/// @param callback callback description
- (SCBluetoothTask *)setSwitchWithNotificationModels:(NSArray<SCPT_NotificationSwitches_Config *> *)notificationModels callback:(SCBCBoolCallback)callback;

@end

//@interface SCNotificationModel : NSObject
//
//@property (nonatomic, assign) SCPT_NotificationType notificationType;
//@property (nonatomic, assign) BOOL state;
//
//@end

NS_ASSUME_NONNULL_END
