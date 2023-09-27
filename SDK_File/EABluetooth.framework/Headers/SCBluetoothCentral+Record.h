//
//  SCBluetoothCentral+Record.h
//  SmartcommWatch
//
//  Created by smartcomm on 2021/5/18.
//

#import "SCBluetoothCentral.h"

NS_ASSUME_NONNULL_BEGIN

@interface SCBluetoothCentral (Record)

/// 获取workout数据的个数
/// @param tenDatasCallback <#tenDatasCallback description#>
/// @param finishCallback <#finishCallback description#>
- (SCBluetoothTask *)getWorkoutListDatasWithTenDatasCallback:(void (^)(NSArray <SCPT_WorkoutResult *> *workouts))tenDatasCallback finishCallback:(void (^)(NSArray <SCPT_WorkoutResult *>*workouts, NSError *error))finishCallback;

/// 根据ID获取workout详情
/// @param id_p <#id_p description#>
/// @param tenDatasCallback <#tenDatasCallback description#>
/// @param finishCallback <#finishCallback description#>
- (SCBluetoothTask *)getWorkoutDetailWithID:(uint32_t)id_p tenDatasCallback:(void (^)(NSArray <SCPT_WorkoutDetail *> *workoutDetails, NSInteger recordCount, NSInteger postBackCount))tenDatasCallback finishCallback:(void (^)(NSArray <SCPT_WorkoutDetail *>*workoutDetails, NSError *error))finishCallback;
@end

NS_ASSUME_NONNULL_END
