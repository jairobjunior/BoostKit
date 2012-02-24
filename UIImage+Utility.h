//  UIImage+Utility.h
//  BoostKit
//
//  Created by Jacques Pienaar on 24/2/12.
// 
//

@interface UIImage (Utility)

+ (UIImage*)roundCornersOfImage:(UIImage *)source theCornerSize:(NSInteger)cornerSize;

+(UIImage *)makeRoundCornerImage:(UIImage*)img :(int) cornerWidth :(int) cornerHeight;

- (UIImage *)fixOrientation;

- (UIImage*)imageWithImage:(UIImage*)image scaledToSize:(CGSize)newSize;

- (UIImage*)maskImage:(UIImage*)image withMask:(UIImage*)maskImage;

@end
