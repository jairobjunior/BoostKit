//
//  UINavigationBar+CustomBackground.m
//  BoostKit
//
//  Created by Jacques Pienaar on 24/2/12.
// 
//

#import "UINavigationBar+CustomBackground.h"

@implementation UINavigationBar(CustomBackground)

+ (UIImage *) bgImagePortrait {
    static UIImage *image = nil;
    if (image == nil) {
        image = [[UIImage imageNamed:@"NavBarBackground.png"] retain];
    }

    return image;
}

+ (UIImage *) bgImageLandscape {
    static UIImage *image = nil;
    if (image == nil) {
        image = [[UIImage imageNamed:@"NavBarBackground.png"] retain];
    }

    return image;
}

- (void) drawLayer:(CALayer *)layer inContext:(CGContextRef)ctx {
    if ([self isMemberOfClass:[UINavigationBar class]] == NO) {
        return;
    }

    UIImage *image = (self.frame.size.width > 320) ?
                        [UINavigationBar bgImageLandscape] : [UINavigationBar bgImagePortrait];

    CGContextTranslateCTM(ctx, 0, image.size.height);
    CGContextScaleCTM(ctx, 1.0, -1.0);
    CGContextDrawImage(ctx, CGRectMake(0, 0, self.frame.size.width, self.frame.size.height), image.CGImage);
}

@end