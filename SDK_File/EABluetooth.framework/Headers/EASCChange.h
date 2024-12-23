//
//  EASCChange.h
//  EABluetooth
//
//  Created by Aye on 2023/9/12.
//

#import <Foundation/Foundation.h>
#import <EABluetooth/SCBluetoothSDK.h>
#import <EABluetooth/EAReminderModel.h>
#import <EABluetooth/EAMonitorReminder.h>
#import <EABluetooth/EASavePBDataModel.h>
NS_ASSUME_NONNULL_BEGIN

@interface EASCChange : NSObject





#pragma mark - Reminder
+ (SCPT_Remind *)eascConvertEAReminder:(EAReminderModel *)eaReminderModel;
+ (SCPT_Remind *)eascConvertEAReminder:(EAReminderModel *)eaReminderModel id_p:(NSInteger)id_p;
+ (EAReminderModel *)eascConvertSCRemind:(SCPT_Remind *)scRemind;
+ (NSInteger)eascGetCanUseReminderId:(NSArray *)reminderIds;


#pragma mark - MonitorReminder
+ (EAMonitorReminder *)eascConvertSCDrinkwater:(SCPT_Drinkwater *)scDrinkwater;
+ (SCPT_Drinkwater *)eascConvertEAMonitorReminder_Drinkwater:(EAMonitorReminder *)eaMonitorReminder;

+ (EAMonitorReminder *)eascConvertSCWashHands:(SCPT_WashHands *)scWashHands;
+ (SCPT_WashHands *)eascConvertEAMonitorReminder_WashHands:(EAMonitorReminder *)eaMonitorReminder;

#pragma mark - Goal
+ (SCPT_Goal *)eascConvertEADailyGoalModel:(EADailyGoalModel *)eaDailyGoalModel;
+ (EADailyGoalModel *)eascConvertSCGoal:(SCPT_Goal *)scGoal;


#pragma mark - UserInfo
+ (SCPT_UserInfo *)eascConvertEAUserModel:(EAUserModel *)eaUserModel;
+ (EAUserModel *)eascConvertSCUserInfo:(SCPT_UserInfo *)scUserInfo;

#pragma mark - Weather
+ (SCPT_Weather *)eascConvertEAWeatherModel:(EAWeatherModel *)eaWeatherModel;

#pragma mark - BigData
+ (void)getSCBigData;
+ (NSArray *)analyzeSCBigData:(EASCBigDataItemModel *)itemModel;
+ (void)getWorkoutDetail:(uint32_t )sportId finishCallback:(void (^)(NSArray <SCPT_WorkoutDetail *>*workoutDetails, NSError *error))finishCallback;


#pragma mark - 运动类型
+ (EAWatchSportType)eascConverSCSportType:(SCPT_WorkoutType)scSportType;

+ (instancetype)defaultChange;
- (void)setTime0 ;
@end

NS_ASSUME_NONNULL_END
