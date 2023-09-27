//
//  SC_RestorePool.h
//  SCBluetoothSDK
//
//  Created by 李永彬 on 2020/12/15.
//

#import <Foundation/Foundation.h>
#import "SC_CBCentralManagerDelegateProxy.h"

NS_ASSUME_NONNULL_BEGIN

@interface SC_RestorePool : NSObject<SC_CBCentralManagerRestoreDelegate>

/*
 恢复蓝牙连接
 */
- (void) reconnectPeripheralFromRestoreState;

@end

NS_ASSUME_NONNULL_END
