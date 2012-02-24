//
//  NSArray+Utility.m
//  BoostKit
//
//  Created by Jacques Pienaar on 24/2/12.
// 
//
#import "NSArray+Utility.h"

@implementation NSArray (Utility)

- (id)firstObject{
	return [self objectAtIndex:0];
}

- (id)secondObject{
	return [self objectAtIndex:1];
}

@end