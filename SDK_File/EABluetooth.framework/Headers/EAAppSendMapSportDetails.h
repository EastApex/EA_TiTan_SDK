//
//  EAAppSendSportDetails.h
//  EABluetooth
//
//  Created by Aye on 2022/12/14.
//

#import <EABluetooth/EABluetooth.h>

NS_ASSUME_NONNULL_BEGIN


/// id = 47 ：发送APP记录运动信息[运动暂停后，需要停止发送此命令，如果需要恢复运动，继续发此命名给手表即可]
/// id = 47: send APP to record the motion information [after the motion is suspended, you need to stop sending this command, if you need to resume the motion, you can continue to send this name to the watch]
@interface EAAppSendMapSportDetails : EABaseModel

/// 当前总运动时长(单位:秒)
/// Current total exercise duration (unit: second)
@property(nonatomic, assign) NSInteger duration;

/// 当前总距离（单位:厘米）
/// Current total distance (unit: cm)
@property(nonatomic, assign) NSInteger distance;

/// 当前配速（单位: S/KM）
/// Current pace (unit: S/KM)
@property(nonatomic, assign) NSInteger pace;


+ (instancetype )eaInitWithDuration:(NSInteger)duration distance:(NSInteger)distance pace:(NSInteger)pace;


@end

NS_ASSUME_NONNULL_END
