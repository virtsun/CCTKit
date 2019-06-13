//
//  UIImage+MXAddtion.h
//  MXBBLibrary
//
//  Created by 张强 on 15/6/26.
//  Copyright (c) 2015年 xntech. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (MXAddtion)

+ (UIImage*)imageWithImage:(UIImage*)sourceImage scaledToSizeWithSameAspectRatio:(CGSize)targetSize;
- (UIImage*)imageWithBlendMode:(CGBlendMode)blendMode tintColor:(UIColor *)tintColor;
- (UIImage *)getPartOfImage:(UIImage *)img rect:(CGRect)partRect;
+ (id)createRoundedRectImage:(UIImage*)image size:(CGSize)size radius:(NSInteger)r;

@end
