//
//  NSObject+Boost.h
//  BoostKit
//
//  Created by Jacques Pienaar on 24/2/12.
// 
//

@interface NSObject (Utility)

- (id)performSelector:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3;
- (id)performSelector:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3 withObject:(id)p4;

- (void)performSelectorInBackground:(SEL)selector withObject:(id)p1 withObject:(id)p2;
- (void)performSelectorInBackground:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3;
- (void)performSelectorInBackground:(SEL)selector withObject:(id)p1 withObject:(id)p2 withObject:(id)p3 withObject:(id)p4;

@end
