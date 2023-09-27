//
//  NSError+SCBluetooth.h
//  SCBluetooth
//
//  Created by 李永彬 on 2020/12/8.

#import <Foundation/Foundation.h>
#import "SCBluetoothError.h"

@interface NSError (SCBluetooth)

+ (NSError *) paramsError;
+ (NSError *) dataFormatError;
+ (NSError *) disconnectError;
+ (NSError *) unsuportDeviceError;
+ (NSError *) deviceErrorWithCode:(NSInteger)code;
+ (NSError *) taskCanelError;
+ (NSError *) powerOffError;
+ (NSError *) workoutRunningError;

@end
