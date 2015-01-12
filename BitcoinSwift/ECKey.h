//
//  ECKey.h
//  BitcoinSwift
//
//  Created by Kevin Greene on 6/15/14.
//  Copyright (c) 2014 DoubleSha. All rights reserved.
//

#import <Foundation/Foundation.h>

@class BigInteger;
@class SecureData;

/// Represents a private/public EC key pair, created using the secp256k1 curve.
@interface ECKey : NSObject

+ (BigInteger *)curveOrder;
+ (const int)privateKeyLength;
+ (const int)publicKeyLength;

@property(nonatomic, readonly) SecureData *privateKey;
@property(nonatomic, readonly) NSData *publicKey;

- (instancetype)init;
- (instancetype)initWithPrivateKey:(SecureData *)privateKey;
- (instancetype)initWithPublicKey:(NSData *)publicKey;

/// Returns the signature for the provided hash. Only supports 256-bit hash.
- (NSData *)signatureForHash:(NSData *)hash;
- (BOOL)verifySignature:(NSData *)signature forHash:(NSData *)hash;

@end
