//
//  SCBluetoothCentral+DeviceOperation.h
//  SmartcommWatch
//
//  Created by 李永彬 on 2021/2/24.
//

#import "SCBluetoothCentral.h"
#import "Scpro.pbobjc.h"

typedef NS_ENUM(NSInteger, SCSwitchType){
    SCSwitchTypeNotification = 0,  /** 通知开关 */
    SCSwitchTypeWristFlick,        /** 抬手亮屏开关 */
    SCSwitchTypeDisturb,           /** 勿扰模式开关 */
    SCSwitchTypeAirplaneMode,      /** 飞行模式开关 */
    SCSwitchTypeGps,               /** GPS开关 */
    SCSwitchTypeStress,            /** 压力检测开关 */
    SCSwitchTypeVibration,         /** 震动开关 */
    SCSwitchTypeBasicCal           /** 静态卡路里开关 */
};
@class SCSwitchModel;

NS_ASSUME_NONNULL_BEGIN

typedef void (^SCSwitchStateCallback)(NSArray<SCSwitchModel *> * _Nullable models, NSError * _Nullable error);

@interface SCBluetoothCentral (DeviceOperation)

///// 获取设备的时间格式
///// @param callback <#callback description#>
//- (SCBluetoothTask *)getTimeFormatWithCallback:(void(^)(SCPT_Format_Time timeFormat, NSError *error))callback;

/// 获取设备的mac地址
/// @param callback <#callback description#>
- (SCBluetoothTask *)getDeviceMacMapFormatWithCallback:(SCBCStringCallback)callback;

//设置时间小时制（12H或者24H）
- (SCBluetoothTask *)setTimeWith24H:(BOOL)is24H callback:(SCBCBoolCallback)callback;


///获取设备开关的状态（抬手亮屏开关状态和通知开关等）
/// @param callback <#callback description#>
- (SCBluetoothTask *)getDeviceSwitchesWithCallback:(void(^)(SCPT_Switches *switches, NSError *error))callback;

- (SCBluetoothTask *)setDeviceSwitches:(SCPT_Switches *)switches callback:(SCBCBoolCallback)callback;;


- (SCBluetoothTask *)setwristFlickSwitchState:(BOOL)switchState callback:(SCBCBoolCallback)callback;

//设置亮屏时间
- (SCBluetoothTask *)setScreenTimeValue:(NSInteger)screenTimeValue callback:(SCBCBoolCallback)callback;

//获取亮屏时间
- (SCBluetoothTask *)getScreenTimCallback:(SCBCIntegerCallback)callback;

/// 设置生理周期
/// @param menstrualStartTimestamp <#menstrualStartTimestamp description#>
/// @param menstrualEndTimestamp <#menstrualEndTimestamp description#>
/// @param fertileStartTimestamp <#fertileStartTimestamp description#>
/// @param fertileEndTimestamp <#fertileEndTimestamp description#>
/// @param ovulationDayTimestamp <#ovulationDayTimestamp description#>
/// @param callback <#callback description#>
- (SCBluetoothTask *)setMenstrualWithMenstrualStartTimestamp:(NSInteger)menstrualStartTimestamp
                                       menstrualEndTimestamp:(NSInteger)menstrualEndTimestamp
                                       fertileStartTimestamp:(NSInteger)fertileStartTimestamp
                                         fertileEndTimestamp:(NSInteger)fertileEndTimestamp
                                       ovulationDayTimestamp:(NSInteger)ovulationDayTimestamp
                                                    callback:(SCBCBoolCallback)callback;

@end

@interface SCSwitchModel : NSObject

@property(nonatomic, assign) BOOL S;
@property(nonatomic, assign) SCSwitchType type;

+ (SCSwitchModel *)modelWithSwitch:(BOOL)S type:(SCSwitchType)type;

@end

NS_ASSUME_NONNULL_END
