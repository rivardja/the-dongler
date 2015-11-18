//
//  Dongle.h
//  Dongler
//
//  Created by Joseph Rivard on 11/18/15.
//  Copyright © 2015 LiftMaster. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

/*
 
 Dongle <CBPeripheralDelegate>
 .
 
 - WriteMessage(message..., ^{})
 - ReadMessage(message..., ^{})
 - Reset
 
 ~
 . messageQueue
 .
 
 - WriteData
 - ReadData
 

 
 */

typedef struct {
    uint16_t messageId;
    uint8_t payload[3];
} dongleMessage_t;


@interface Dongle : NSObject<CBPeripheralDelegate>

- (void)writeData:(NSData*)data toUUID:(CBUUID*)uuid;
- (NSData*)readDataFromUUID:(CBUUID*)uuid;

+ (Dongle*)withPeripheral:(CBPeripheral*)peripheral;

@end
