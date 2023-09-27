//
//  SCBluetoothCentral+Test.h
//  SmartCommTestTool
//
//  Created by smartcomm on 2021/5/31.
//

#import "SCBluetoothCentral.h"

NS_ASSUME_NONNULL_BEGIN

@interface SCBluetoothCentral (Test)

/// 批量测试
/// @param fwVer <#fwVer description#>
/// @param tpVer <#tpVer description#>
/// @param fontVer <#fontVer description#>
/// @param gpsVer <#gpsVer description#>
/// @param tempDif <#tempDif description#>
/// @param callback <#callback description#>
- (SCBluetoothTask *)batchFactoryTestWithFwVer:(NSString *)fwVer tpVer:(NSString *)tpVer fontVer:(NSString *)fontVer gpsVer:(NSString *)gpsVer tempDif:(uint32_t)tempDif callback:(SCBCBoolCallback)callback;

/// 持续读取NTC温度
- (SCBluetoothTask *)queryNtcTemperatureSustained;

/// 读取手腕温度
/// @param callback <#callback description#>
- (SCBluetoothTask *)queryNstTemperatureCallback:(SCBCBoolCallback)callback;

- (SCBluetoothTask *)writeSerialNumWithNum:(NSString *)number callback:(SCBCBoolCallback)callback;

/// 读取flash地址
/// @param address <#address description#>
/// @param size <#size description#>
- (SCBluetoothTask *)queryFlashAddressSustainedWithAddress:(uint32_t)address size:(uint32_t)size;

/// 清空log
/// @param callback <#callback description#>
- (SCBluetoothTask *)clearLogWithCallback:(SCBCBoolCallback)callback;

@end

NS_ASSUME_NONNULL_END
