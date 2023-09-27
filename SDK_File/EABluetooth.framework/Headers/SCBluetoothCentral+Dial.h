//
//  SCBluetoothCentral+Dial.h
//  SmartcommWatch
//
//  Created by 李永彬 on 2021/4/13.
//

#import "SCBluetoothCentral.h"

NS_ASSUME_NONNULL_BEGIN

@interface SCBluetoothCentral (Dial)

//设置表盘
- (SCBluetoothTask *)setDialWithDialId:(NSInteger)dialId callback:(SCBCBoolCallback)callback;

- (SCBluetoothTask *)getDialIdCallback:(void(^)(SCPT_Watchface *watchface, NSError *error))callback;

//获取设备上表盘的Id
- (SCBluetoothTask *)getDialListCallback:(void(^)(NSArray *idsArray, NSError *error))callback;

@end

NS_ASSUME_NONNULL_END
