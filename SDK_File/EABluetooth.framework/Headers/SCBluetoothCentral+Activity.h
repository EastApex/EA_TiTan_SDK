//
//  SCBluetoothCentral+Activity.h
//  SmartcommWatch
//
//  Created by 李永彬 on 2021/3/30.
//

#import "SCBluetoothCentral.h"

NS_ASSUME_NONNULL_BEGIN

@interface SCBluetoothCentral (Activity)

/// 获取运动数据
/// @param tenDatasCallback <#tenDatasCallback description#>
/// @param finishCallback <#finishCallback description#>
- (SCBluetoothTask *)getSportDatasWithTenDatasCallback:(void (^)(NSArray <SCPT_Activity *>*tenSportArray))tenDatasCallback finishCallback:(void (^)(NSArray <SCPT_Activity *>*sportArray, NSError *error))finishCallback;

/// 获取睡眠数据
/// @param tenDatasCallback postBackCount 多少条回传一次 sleepCount总数据条数  tenSleepArray 每次回传的具体数据
/// @param finishCallback <#finishCallback description#>
- (SCBluetoothTask *)getSleepDatasWithTenDatasCallback:(void (^)(NSArray <SCPT_Sleep *>*tenSleepArray, NSInteger sleepCount, NSInteger postBackCount))tenDatasCallback finishCallback:(void (^)(NSArray <SCPT_Sleep *>*sleepArray, NSError *error))finishCallback;

/// 获取心率数据
/// @param tenDatasCallback tenDatasCallback description
/// @param finishCallback <#finishCallback description#>
- (SCBluetoothTask *)getHeartRateDatasWithTenDatasCallback:(void (^)(NSArray <SCPT_Heartrate *>*tenHeartRateArray))tenDatasCallback finishCallback:(void (^)(NSArray <SCPT_Heartrate *>*heartRateArray, NSError *error))finishCallback;

/// 获取血氧数据
/// @param tenDatasCallback <#tenDatasCallback description#>
/// @param finishCallback <#finishCallback description#>
- (SCBluetoothTask *)getSpo2DatasWithTenDatasCallback:(void (^)(NSArray <SCPT_SpO2Data *>*tenSpo2Array))tenDatasCallback finishCallback:(void (^)(NSArray <SCPT_SpO2Data *>*spo2Array, NSError *error))finishCallback;

/// 获取心理压力数据
/// @param tenDatasCallback <#tenDatasCallback description#>
/// @param finishCallback <#finishCallback description#>
- (SCBluetoothTask *)getStressDatasWithTenDatasCallback:(void (^)(NSArray <SCPT_StressData *>*tenStressArray))tenDatasCallback finishCallback:(void (^)(NSArray <SCPT_StressData *>*stressArray, NSError *error))finishCallback;

/// 获取温度数据
/// @param tenDatasCallback <#tenDatasCallback description#>
/// @param finishCallback <#finishCallback description#>
- (SCBluetoothTask *)getTemperatureDatasWithWithTenDatasCallback:(void (^)(NSArray <SCPT_BodyTemperatureData *>*tenTemperatureArray))tenDatasCallback finishCallback:(void (^)(NSArray <SCPT_BodyTemperatureData *>*temperatureArray, NSError *error))finishCallback;

@end

NS_ASSUME_NONNULL_END
