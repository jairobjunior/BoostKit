//
//  Macros.h
//  BoostKit
//
//  Created by Jacques Pienaar on 24/2/12.
// 
//

#import <MobileCoreServices/UTCoreTypes.h>
#import <CoreMotion/CoreMotion.h>

// TYPES
#define BOX_BOOL(x) [NSNumber numberWithBool:(x)]
#define BOX_INT(x) [NSNumber numberWithInt:(x)]
#define BOX_SHORT(x) [NSNumber numberWithShort:(x)]
#define BOX_LONG(x) [NSNumber numberWithLong:(x)]
#define BOX_UINT(x) [NSNumber numberWithUnsignedInt:(x)]
#define BOX_FLOAT(x) [NSNumber numberWithFloat:(x)]
#define BOX_DOUBLE(x) [NSNumber numberWithDouble:(x)]

#define UNBOX_BOOL(x) [(x) boolValue]
#define UNBOX_INT(x) [(x) intValue]
#define UNBOX_SHORT(x) [(x) shortValue]
#define UNBOX_LONG(x) [(x) longValue]
#define UNBOX_UINT(x) [(x) unsignedIntValue]
#define UNBOX_FLOAT(x) [(x) floatValue]
#define UNBOX_DOUBLE(x) [(x) doubleValue]

// MEMORY

// NEW VERSIONS
#define SAFE_RELEASE(obj) ([obj release], obj = nil)
#define SAFE_TIMER_RELEASE(obj) ([obj invalidate], [obj release], obj = nil)
#define SAFE_ASSIGN(obj, expr) ([(expr) retain], [obj release], obj = (expr))

// BOUNDS
#define RECT_CENTER(rect) CGPointMake(CGRectGetMidX(rect),CGRectGetMidY(rect))
#define RECT_WITH_WIDTH_HEIGHT(rect, width, height) CGRectMake((rect).origin.x, (rect).origin.y, (width), (height))
#define RECT_WITH_WIDTH(rect, width) CGRectMake((rect).origin.x, (rect).origin.y, (width), (rect).size.height)
#define RECT_WITH_HEIGHT(rect, height) CGRectMake((rect).origin.x, (rect).origin.y, (rect).size.width, (height))

#define RECT_INSET_BY_LEFT_TOP_RIGHT_BOTTOM(rect, left, top, right, bottom) CGRectMake(rect.origin.x + (left), rect.origin.y + (top), rect.size.width - (left) - (right), rect.size.height - (top) - (bottom))
#define RECT_INSET_BY_TOP_BOTTOM(rect, top, bottom) CGRectMake(rect.origin.x, rect.origin.y + (top), rect.size.width, rect.size.height - (top) - (bottom))
#define RECT_INSET_BY_LEFT_RIGHT(rect, left, right) CGRectMake(rect.origin.x + (left), rect.origin.y, rect.size.width - (left) - (right), rect.size.height)

#define RECT_STACKED_OFFSET_BY_X(rect, offset) CGRectMake(rect.origin.x + rect.size.width + (offset), rect.origin.y, rect.size.width, rect.size.height)
#define RECT_STACKED_OFFSET_BY_Y(rect, offset) CGRectMake(rect.origin.x, rect.origin.y + rect.size.height + (offset), rect.size.width, rect.size.height)

// GEOMETRY
#define DEG_TO_RAD(degrees) ((degrees) * M_PI / 180.0)
#define RAD_TO_DEG(radians) ((radians) * 180.0 / M_PI)

// SELECTORS
#define SEL(x) @selector(x)

// STRINGS
#define IS_EMPTY_STRING(str) (!(str) || ![(str) isKindOfClass:NSString.class] || [(str) length] == 0)
#define IS_POPULATED_STRING(str) ((str) && [(str) isKindOfClass:NSString.class] && [(str) length] > 0)

// SCREEN/DISPLAY
#define IS_DEVICE_ORIENTATION_PORTRAIT ([UIDevice currentDevice].orientation == UIDeviceOrientationPortrait)
#define IS_DEVICE_ORIENTATION_LANDSCAPE ([UIDevice currentDevice].orientation == UIDeviceOrientationLandscapeLeft || [UIDevice currentDevice].orientation == UIDeviceOrientationLandscapeRight)
#define IS_DEVICE_ORIENTATION_LANDSCAPE_LEFT ([UIDevice currentDevice].orientation == UIDeviceOrientationLandscapeLeft)
#define IS_DEVICE_ORIENTATION_LANDSCAPE_RIGHT ([UIDevice currentDevice].orientation == UIDeviceOrientationLandscapeRight)
#define IS_DEVICE_ORIENTATION_PORTRAIT_UPSIDE_DOWN ([UIDevice currentDevice].orientation == UIDeviceOrientationPortraitUpsideDown)
#define IS_DEVICE_ORIENTATION_FACE_UP ([UIDevice currentDevice].orientation == UIDeviceOrientationFaceUp)
#define IS_DEVICE_ORIENTATION_FACE_DOWN ([UIDevice currentDevice].orientation == UIDeviceOrientationFaceDown)

#define HARDWARE_SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)
#define HARDWARE_SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)

// DUMPS
#define BOOL_TO_STRING(theBool) ((theBool ? @"Yes" : @"No"))
#define INT_TO_STRING(theInt) ([NSString stringWithFormat:@"%d",theInt])
#define FLOAT_TO_STRING(theFloat) ([NSString stringWithFormat:@"%0.1f",theFloat])

#define RECT_TO_STR(r) ([NSString stringWithFormat:@"X=%0.1f Y=%0.1f W=%0.1f H=%0.1f", (r).origin.x, (r).origin.y, (r).size.width, (r).size.height])
#define POINT_TO_STR(p) ([NSString stringWithFormat:@"X=%0.1f Y=%0.1f", (p).x, (p).y])
#define SIZE_TO_STR(s) ([NSString stringWithFormat:@"W=%0.1f H=%0.1f", (s).width, (s).height])

// HARDWARE/DEVICE INFO
#define DEVICE_UDID ([UIDevice currentDevice].uniqueIdentifier)

#define IS_IPAD ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPad)
#define IS_IPHONE ([UIDevice currentDevice].userInterfaceIdiom == UIUserInterfaceIdiomPhone)

// HARDWARE/DEVICE CAPABILITY
#define IS_CLASSIC_DISPLAY (([UIScreen mainScreen].scale < 1.5F))
#define IS_RETINA_DISPLAY (([UIScreen mainScreen].scale > 1.5F))

#define IS_MULTITASKING_IN_SDK ([[UIDevice currentDevice] respondsToSelector:@selector(isMultitaskingSupported)] && [[UIDevice currentDevice] isMultitaskingSupported] == YES) 
#define IS_CAMERA_IN_SDK ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera])

// VIEW 
#define CENTER UIViewAutoresizingFlexibleLeftMargin | UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleBottomMargin

// COLORS
#define RGB256_TO_COL(col) ((col) / 255.0f)
#define COL_TO_RGB256(col) ((int)((col) * 255.0))
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define COLOR(r,g,b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1]

// ENVIRONMENT VARIABLES
#define ENVIRONMENT_VARS [[NSProcessInfo processInfo] environment]

// DIRECTORIES
#define DOCUMENTS_DIR ([NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject])

