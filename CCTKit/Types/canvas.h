//
//  canvas.h
//  qualitymarket
//
//  Created by sunlantao on 2018/12/10.
//  Copyright © 2018年 sunlantao. All rights reserved.
//

//特指设备的窄边
#define ScreenNarrowSide MIN(CGRectGetWidth([UIScreen mainScreen].bounds), CGRectGetHeight([UIScreen mainScreen].bounds))

//特指设备的宽边
#define ScreenWideSide MAX(CGRectGetWidth([UIScreen mainScreen].bounds), CGRectGetHeight([UIScreen mainScreen].bounds))

#define AspectScale(measure) ((measure) *(ScreenNarrowSide/375.f))


#define IPhoneXSafeAreaPotraitTop 44
#define IPhoneXSafeAreaPotraitBottom 34
#define IPhoneXSafeAreaPotraitLeft 0
#define IPhoneXSafeAreaPotraitRight 0

#define IPhoneXSafeAreaLanscapeTop 0
#define IPhoneXSafeAreaLanscapeBottom 21
#define IPhoneXSafeAreaLanscapeLeft 44
#define IPhoneXSafeAreaLanscapeRight 44

#ifndef RGBACOLOR
#define UIColorFromRGBA(rgbValue, a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:a]
#define UIColorFromRGB(rgbValue) UIColorFromRGBA(rgbValue, 1.f)
#endif

#pragma mark -- Colors

#define COLOR_MAIN UIColorFromRGB(0xF5106E)
#define COLOR_GRAY_BACKGROUND UIColorFromRGB(0xf8f8f8)
#define COLOR_SEPERATOR UIColorFromRGB(0xe1e1e1)

#define COLOR_PINK UIColorFromRGB(0xFF2A9B)
#define COLOR_BLUE UIColorFromRGB(0x34C9FF)

#define FontSystem(size) [UIFont systemFontOfSize:size]
#define FontBoldSystem(size) [UIFont boldSystemFontOfSize:size]

#define FontWSystem(size, w) [UIFont systemFontOfSize:size weight:w]


#pragma mark -- Size

//判断是否是ipad
#define iPad() ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)

#define iPhoneX() ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhoneXs() ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1624), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhoneXMax() ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhoneXR() ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) : NO)

#define iPhoneXSeries() (iPhoneX() || iPhoneXs() || iPhoneXMax() || iPhoneXR())

#define UIToolBarHeight (iPhoneXSeries()?83:49)
#define UINavigationHeight (iPhoneXSeries()?88:64)
#define UIStatusHeight (iPhoneXSeries()?44:20)


#pragma mark -- images --
#define IMAGE_BLACK_BORDER [[UIImage imageNamed:@"btn_white_smaller_n"] resizableImageWithCapInsets:UIEdgeInsetsMake(0, 20, 0, 20) resizingMode:UIImageResizingModeStretch]
#define IMAGE_YELLOW_BACKGROUND [[UIImage imageNamed:@"btn_yellow_n"] resizableImageWithCapInsets:UIEdgeInsetsMake(0, 20, 0, 20) resizingMode:UIImageResizingModeStretch]
#define IMAGE_HEADER_DEFAULT [UIImage imageNamed:@"avatar_default_big"]
#define IMAGE_BACKGROUND_DEFAULT [UIImage imageNamed:@"icons_bg"]

