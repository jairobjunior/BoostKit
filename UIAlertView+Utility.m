//
//  UIAlertView+Utility.m
//  BoostKit
//
//  Created by Jacques Pienaar on 24/2/12.
// 
//
#import "UIAlertView+Utility.h"

@implementation UIAlertView (Utility)

+ (UIAlertView *)alertViewFromError:(NSError *)error {
	
	UIAlertView *result = [[[UIAlertView alloc] initWithTitle:[error localizedFailureReason]
													  message:[error localizedDescription]
													 delegate:nil
											cancelButtonTitle:NSLocalizedString(@"OK", @"")
											otherButtonTitles:nil] autorelease];
	return result;
}

+ (void)showWithTitle:(NSString *)title message:(NSString *)message {

	[[[[UIAlertView alloc] initWithTitle:title
													 message:message
													delegate:nil
										   cancelButtonTitle:NSLocalizedString(@"OK", @"")
										   otherButtonTitles:nil] autorelease] show]; 
}

+ (void)showWithMessage:(NSString *)message {
	[UIAlertView showWithTitle:nil message:message];
}

+ (void)showNonClosebleMessage:(NSString *)message {
	[[[[UIAlertView alloc] initWithTitle:nil 
                                 message:message 
                                delegate:nil 
                       cancelButtonTitle:nil 
                       otherButtonTitles:nil] autorelease] show];
}

@end
