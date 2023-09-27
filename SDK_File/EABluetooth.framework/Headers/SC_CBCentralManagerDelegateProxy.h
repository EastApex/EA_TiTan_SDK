//
//  sss.h
//  SCBluetoothSDK
//
//  Created by 李永彬 on 2020/12/14.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SC_CBCentralManagerStateDelegate <NSObject>

- (void)centralManagerDidUpdateState:(CBCentralManager *)central;

@end

@protocol SC_CBCentralManagerRestoreDelegate <NSObject>

- (void)centralManager:(CBCentralManager *)central willRestoreState:(NSDictionary<NSString *, id> *)dict;

@end

@protocol SC_CBCentralManagerDiscoveryDelegate <NSObject>

- (void)centralManager:(CBCentralManager *)central didDiscoverPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary<NSString *, id> *)advertisementData RSSI:(NSNumber *)RSSI;

@end

@protocol SC_CBCentralManagerConnectionDelegate <NSObject>

- (void)centralManager:(CBCentralManager *)central didConnectPeripheral:(CBPeripheral *)peripheral;

- (void)centralManager:(CBCentralManager *)central didFailToConnectPeripheral:(CBPeripheral *)peripheral error:(nullable NSError *)error;

- (void)centralManager:(CBCentralManager *)central didDisconnectPeripheral:(CBPeripheral *)peripheral error:(nullable NSError *)error;

@end

@interface SC_CBCentralManagerDelegateProxy : NSObject<CBCentralManagerDelegate>

@property (nonatomic, weak, nullable) id <SC_CBCentralManagerStateDelegate> stateDelegate;
@property (nonatomic, weak, nullable) id <SC_CBCentralManagerRestoreDelegate> restoreDelegate;
@property (nonatomic, weak, nullable) id <SC_CBCentralManagerDiscoveryDelegate> discoveryDelegate;
@property (nonatomic, weak, nullable) id <SC_CBCentralManagerConnectionDelegate> coonnetcionDelegate;
- (instancetype)initWithStateDelegate:(id<SC_CBCentralManagerStateDelegate>)stateDelegate
                      restoreDelegate:(id<SC_CBCentralManagerRestoreDelegate>)restoreDelegate
                    discoveryDelegate:(id<SC_CBCentralManagerDiscoveryDelegate>)discoveryDelegate
                   connectionDelegate:(id<SC_CBCentralManagerConnectionDelegate>)connectionDelegate;

@end

NS_ASSUME_NONNULL_END
