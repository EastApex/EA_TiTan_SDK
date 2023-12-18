//
//  SCBluetoothCentral+Setting.h
//  SmartcommWatch
//
//  Created by 李永彬 on 2021/2/3.
//

#import "SCBluetoothCentral.h"
#import <UIKit/UIKit.h>
#import "Scpro.pbobjc.h"

NS_ASSUME_NONNULL_BEGIN
/**
 星期几[day  of the week]
 例子：星期一、星期二、星期五可表示为
 SCWeek week = SCWeekMonday | SCWeekTuesday | SCWeekFriday;
 
 - SCWeekMonday: 星期一
 - SCWeekTuesday: 星期二
 - SCWeekWednesday: 星期三
 - SCWeekThursday: 星期四
 - SCWeekFriday: 星期五
 - SCWeekSaturday: 星期六
 - SCWeekSunday: 星期日
 */
typedef NS_ENUM(NSInteger, SCWeek) {
    SCWeekSunday = (0x01 << 0),
    SCWeekMonday = (0x01 << 1),
    SCWeekTuesday = (0x01 << 2),
    SCWeekWednesday = (0x01 << 3),
    SCWeekThursday = (0x01 << 4),
    SCWeekFriday = (0x01 << 5),
    SCWeekSaturday = (0x01 << 6),
};

typedef NS_ENUM(NSInteger, SCReminderType) {
    SCReminderTypeEat = 0,       // 吃饭[eat]
    SCReminderTypeTakePills, // 吃药[take pills]
    SCReminderTypeDrinkWater,// 喝水[drinkwater]
    SCReminderTypeSleep,     // 睡觉[sleep]
//    SCReminderTypeAwake = 0x04,     // 清醒[awake]
    SCReminderTypeSport,     // 运动[sport]
    SCReminderTypeMeeting,   // 会议[meeting]
    SCReminderTypeCustom,    // 自定义[custom]
    SCReminderTypeBills,
//    SCReminderTypePersonnel = 0x09,
    SCReminderTypeAlarm,//闹钟
    SCReminderTypeWalkDog//遛狗
};

@interface SCBluetoothCentral (Setting)

/// 获取设备的序列号
/// @param callback callback description
- (SCBluetoothTask *)getSerialNumberCallback:(SCBCStringCallback)callback;

/// 获取设备的固件版本号
/// @param callback callback description
- (SCBluetoothTask *)getDeviceVersionCallback:(void(^)(SCPT_Version *scptVersion, NSError *error))callback;

///// 获取距离的单位 英里/km
///// @param callback <#callback description#>
//- (SCBluetoothTask *)getDistanceUnitWithCallback:(void(^)(SCPT_Format_Distance distance, NSError *error))callback;
//
///// 获取温度的单位 摄氏度/华氏度
///// @param callback <#callback description#>
//- (SCBluetoothTask *)getTemperatureUnitWithCallback:(void(^)(SCPT_Format_Temperature temperature, NSError *error))callback;

/// 获取距离、温度、天气、时间的单位 摄氏度/华氏度
/// @param callback <#callback description#>
- (SCBluetoothTask *)getDeviceUnitWithCallback:(void(^)(SCPT_Format *format, NSError *error))callback;

/// 获取心率监控状态
/// @param callback <#callback description#>
- (SCBluetoothTask *)getHeartRateMonitorWithCallback:(void(^)(SCPT_HeartrateMonitor *heartrateMonitor, NSError *error))callback;

/// 获取久坐提醒
/// @param callback <#callback description#>
- (SCBluetoothTask *)getInactivityWithCallback:(void(^)(SCPT_Sedentary *sendentary, NSError *error))callback;

/// 获取洗手提醒
/// @param callback <#callback description#>
- (SCBluetoothTask *)getHandWashWithCallback:(void(^)(SCPT_WashHands *washHans, NSError *error))callback;

/// 获取喝水提醒
/// @param callback <#callback description#>
- (SCBluetoothTask *)getHydrationAlertWithCallback:(void(^)(SCPT_Drinkwater *drankWater, NSError *error))callback;

/// 获取温度alert
/// @param callback <#callback description#>
- (SCBluetoothTask *)getTemperatureAlertWithCallback:(void(^)(SCPT_BodyTemperatureMonitor *bodyTemperature, NSError *error))callback;

/// 获取目标值
/// @param callback <#callback description#>
- (SCBluetoothTask *)getGoalsWithCallback:(void(^)(SCPT_Goal *goal, NSError *error))callback;

/// 获取电池电量
/// @param callback <#callback description#>
- (SCBluetoothTask *)getBatteryWithCallback:(void(^)(NSInteger batteryPercentValue, NSError *error))callback;

/// 获取语言
- (SCBluetoothTask *)getLanguageWithCallback:(void(^)(NSInteger type, NSError *error))callback;

/// 获取绑定信息
/// @param callback YES表示已经绑定 NO表示未绑定或者被重置
- (SCBluetoothTask *)getBindInfoWithCallback:(void(^)(SCPT_BindingInfo *bindingInfo, NSError *error))callback;

- (SCBluetoothTask *)getAgpsInfoWithCallback:(void(^)(SCPT_AgpsRequest *agpsRequest, NSError *error))callback;

#pragma mark - set
/// 设置系统时间到设备
/// @param callback <#callback description#>
- (SCBluetoothTask *)setTimeWithCallback:(SCBCBoolCallback)callback;

/// 切换英制/公制单位
/// @param distance <#distance description#>
/// @param callback <#callback description#>
- (SCBluetoothTask *)setDistanceUnitWithFormat:(SCPT_Format_Distance)distance callback:(SCBCBoolCallback)callback;

/// 设置温度格式F/C
/// @param temperature temperature description
/// @param callback callback description
- (SCBluetoothTask *)setTemperatureWithFormat:(SCPT_Format_Temperature)temperature callback:(SCBCBoolCallback)callback;

/// 设置天气格式F/C
/// @param weather <#weather description#>
/// @param callback callback description
- (SCBluetoothTask *)setWeatherWithFormat:(SCPT_Format_Weather)weather callback:(SCBCBoolCallback)callback;



- (SCBluetoothTask *)setLanguageWithLanguageType:(SCPT_Language_Type)languageType callback:(SCBCBoolCallback)callback;


/// 设置心率监控
/// @param duration 监控时间间隔 单位分钟
/// @param lowThreshold 心率下限
/// @param highThreshold 心率上限
/// @param callback <#callback description#>
- (SCBluetoothTask *)setHeartRateMonitorWithDuration:(NSInteger)duration lowThreshold:(NSInteger)lowThreshold highThreshold:(NSInteger)highThreshold callback:(SCBCBoolCallback)callback;
- (SCBluetoothTask *)setHeartRateMonitorWith:(SCPT_HeartrateMonitor *)scHeartrateMonitor callback:(SCBCBoolCallback)callback;
/// 设置stress监控
/// @param state  开关状态
/// @param callback <#callback description#>
- (SCBluetoothTask *)setStressMonitorWithState:(BOOL)state callback:(SCBCBoolCallback)callback;

/// 设置MotionRecognition
/// @param state <#state description#>
/// @param callback <#callback description#>
- (SCBluetoothTask *)setMotionRecognitionWithState:(BOOL)state callback:(SCBCBoolCallback)callback;

/// 设置久坐提醒
/// @param duration 提醒间隔 单位分钟
/// @param startTime 开始时间 单位秒
/// @param endTime 结束时间 单位秒
/// @param repeatPeriod 重复周期
/// @param callback <#callback description#>
- (SCBluetoothTask *)setInactivityWithDuration:(NSInteger)duration startTime:(NSInteger)startTime endTime:(NSInteger)endTime repeatPeriod:(SCWeek)repeatPeriod callback:(SCBCBoolCallback)callback;

/// 设置洗手
/// @param duration 提醒间隔 单位分钟
/// @param startTime 开始时间 单位秒
/// @param endTime 结束时间 单位秒
/// @param repeatPeriod 重复周期
/// @param callback <#callback description#>
- (SCBluetoothTask *)setHandWashWithDuration:(NSInteger)duration startTime:(NSInteger)startTime endTime:(NSInteger)endTime repeatPeriod:(SCWeek)repeatPeriod callback:(SCBCBoolCallback)callback;

/// 设置喝水提醒
/// @param duration 提醒间隔 单位分钟
/// @param startTime 开始时间 单位秒
/// @param endTime 结束时间 单位秒
/// @param repeatPeriod 重复周期
/// @param callback <#callback description#>
- (SCBluetoothTask *)setHydrationAlertWithDuration:(NSInteger)duration startTime:(NSInteger)startTime endTime:(NSInteger)endTime repeatPeriod:(SCWeek)repeatPeriod callback:(SCBCBoolCallback)callback;

/// 设置温度监测
/// @param duration 时间间隔 单位分钟
/// @param callback <#callback description#>
- (SCBluetoothTask *)setTemperatureAlertWithDuration:(NSInteger)duration callback:(SCBCBoolCallback)callback;
- (SCBluetoothTask *)setTemperatureAlertWith:(SCPT_BodyTemperatureMonitor *)scBodyTemperatureMonitor callback:(SCBCBoolCallback)callback;
/// 设置目标
/// @param goal <#goal description#>
/// @param callback <#callback description#>
- (SCBluetoothTask *)setGoalsWithGoal:(SCPT_Goal *)goal callback:(SCBCBoolCallback)callback;

/// 设置用户信息
/// @param userInfo <#userInfo description#>
/// @param callback <#callback description#>
- (SCBluetoothTask *)setUserInfo:(SCPT_UserInfo *)userInfo callback:(SCBCBoolCallback)callback;

/// 重置设备
/// @param callback <#callback description#>
- (SCBluetoothTask *)setResetDeviceWithCallback:(SCBCBoolCallback)callback;

/// 设置天气
/// @param weathersArray <#weathersArray description#>
/// @param callback <#callback description#>
- (SCBluetoothTask *)setWeatherWithWeatherArray:(NSArray <SCPT_Weather_Day *> *)weathersArray callback:(SCBCBoolCallback)callback;

/// 设置绑定信息
/// @param userId <#userId description#>
/// @param clearData <#clearData description#>
/// @param callback <#callback description#>

- (SCBluetoothTask *)setBindInfoWithUserId:(NSString *)userId clearData:(BOOL)clearData callback:(SCBCBoolCallback)callback ;

/// 客户端进入/退出拍照界面
/// @param state <#state description#>
/// @param callback <#callback description#>
- (SCBluetoothTask *)setCameraWithState:(BOOL)state callback:(SCBCBoolCallback)callback;

//找手机
- (SCBluetoothTask *)hasFindPhone;

#pragma mark - reminder

/// 获取提醒
/// @param callback <#callback description#>
- (SCBluetoothTask *)getRemindersWithCallback:(void(^)(NSArray <SCPT_Remind *> *reminders, NSError *error))callback;

/// 编辑提醒
/// @param ptReminder SCPT_Remind
/// @param callback <#callback description#>
- (SCBluetoothTask *)editRemindersWithReminder:(SCPT_Remind *)ptReminder callback:(SCBCBoolCallback)callback;

/// 添加提醒
/// @param ptReminder SCPT_Remind
/// @param callback <#callback description#>
- (SCBluetoothTask *)addRemindersWithReminder:(SCPT_Remind *)ptReminder callback:(SCBCBoolCallback)callback;

/// 删除提醒
/// @param reminderId <#reminderId description#>
/// @param callback <#callback description#>
- (SCBluetoothTask *)deleteRemindersWithReminderId:(NSInteger)reminderId callback:(SCBCBoolCallback)callback;

@end

NS_ASSUME_NONNULL_END
