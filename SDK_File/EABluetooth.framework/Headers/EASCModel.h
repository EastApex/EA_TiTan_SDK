//
//  EASCModel.h
//  EABluetooth
//
//  Created by Aye on 2023/9/5.
//

#import <EABluetooth/EABluetooth.h>
#import <EABluetooth/SCBluetoothSDK.h>
NS_ASSUME_NONNULL_BEGIN

@interface EASCModel : EABaseModel


@property(nonatomic,strong) SCPT_Version *scVersion;

@property(nonatomic,strong) SCPT_Format *scFormat;

@property(nonatomic,strong) SCPT_WashHands *scWashHands;

@property(nonatomic,strong) SCPT_BodyTemperatureMonitor *scBodyTemperatureMonitor;

@property(nonatomic,strong) SCPT_AgpsRequest *scAgps;

@property(nonatomic,strong) SCPT_Switches *scSwitches;

@property(nonatomic,strong) SCPT_HeartrateMonitor *scHeartrateMonitor;

@property(nonatomic,strong) SCPT_Sedentary *scSedentaryMonitor;

@property(nonatomic,strong) SCPT_Drinkwater *scDrinkwater;

@property(nonatomic,strong) SCPT_NotificationSwitches *scNotificationSwitches;

@property(nonatomic,strong) NSArray *scWatchfaceList;

@property(nonatomic,strong) SCPT_Watchface *scWatchface;
@end

NS_ASSUME_NONNULL_END
