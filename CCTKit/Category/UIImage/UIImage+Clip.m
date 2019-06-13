//
//  UIImage+Clip.m
//  qualitymarket
//
//  Created by sunlantao on 2019/4/10.
//  Copyright © 2019 sunlantao. All rights reserved.
//

#import "UIImage+Clip.h"

@implementation UIImage(Clip)


- (UIImage *)clipCircleWith:(CGFloat)width
                      color:(UIColor *)color
{
    
    CGFloat imageWidth = self.size.width + 2 * width;
    CGFloat imageHeight = self.size.height + 2 * width;
    
    UIGraphicsBeginImageContextWithOptions(CGSizeMake(imageWidth, imageHeight), NO, 0.0);
    
    UIGraphicsGetCurrentContext();
    
    CGFloat radius = (self.size.width < self.size.height
                      ? self.size.width : self.size.height) * 0.5;
    
    UIBezierPath *bezierPath = [UIBezierPath
                                bezierPathWithArcCenter:CGPointMake(imageWidth * 0.5, imageHeight * 0.5)
                                radius:radius startAngle:0 endAngle:M_PI * 2 clockwise:YES];
    
    bezierPath.lineWidth = width;
    [color setStroke];
    [bezierPath stroke];
    [bezierPath addClip];
    
    [self drawInRect:CGRectMake(width, width, self.size.width, self.size.height)];
    
    UIImage *circleImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return circleImage;
}
/**
 *  获取矩形的渐变色的UIImage(此函数还不够完善)
 *
 *  @param bounds       UIImage的bounds
 *  @param colors       渐变色数组，可以设置两种颜色
 *  @param gradientType 渐变的方式：0--->从上到下   1--->从左到右
 *
 *  @return 渐变色的UIImage
 */
+ (UIImage*)gradientImageWithBounds:(CGRect)bounds andColors:(NSArray*)colors andGradientType:(int)gradientType{
    NSMutableArray *ar = [NSMutableArray array];
    
    for(UIColor *c in colors) {
        [ar addObject:(id)c.CGColor];
    }
    UIGraphicsBeginImageContextWithOptions(bounds.size, YES, 1);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSaveGState(context);
    CGColorSpaceRef colorSpaceRef = CGColorSpaceCreateDeviceRGB();
    CGGradientRef gradient = CGGradientCreateWithColors(colorSpaceRef, (CFArrayRef)ar, NULL);
    CGPoint start = CGPointZero;
    CGPoint end = CGPointZero;
    
    switch (gradientType) {
        case 0:
            start = CGPointMake(0.0, 0.0);
            end = CGPointMake(0.0, bounds.size.height);
            break;
        case 1:
            start = CGPointMake(0.0, 0.0);
            end = CGPointMake(bounds.size.width, 0.0);
            break;
    }
    CGContextDrawLinearGradient(context, gradient, start, end, kCGGradientDrawsBeforeStartLocation | kCGGradientDrawsAfterEndLocation);
    UIImage *image = UIGraphicsGetImageFromCurrentImageContext();
    CGGradientRelease(gradient);
    CGContextRestoreGState(context);
    CGColorSpaceRelease(colorSpaceRef);
    UIGraphicsEndImageContext();
    return image;
}

// 自定义裁剪算法
- (UIImage *)clipWithCornerRadius:(CGFloat)c {
    int w = self.size.width * self.scale;
    int h = self.size.height * self.scale;
    CGRect rect = CGRectMake(0, 0, w, h);
    //使用贝塞尔
    UIGraphicsBeginImageContextWithOptions(CGSizeMake(w, h), false, 1.0);
    [[UIBezierPath bezierPathWithRoundedRect:rect cornerRadius:c] addClip];
    [self drawInRect:rect];
    UIImage *ret = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return ret;
}

@end
