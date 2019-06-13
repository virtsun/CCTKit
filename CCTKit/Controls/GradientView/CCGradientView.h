//
//  CCGradientView.h
//  qualitymarket
//
//  Created by sunlantao on 2019/1/17.
//  Copyright © 2019 sunlantao. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, CCGradientViewDirection){
    kkCCGradientViewDirectionHorizonal,
    kkCCGradientViewDirectionHorizonalReverse,
    kkCCGradientViewDirectionVertical,
    kkCCGradientViewDirectionVerticalReverse
};

NS_ASSUME_NONNULL_BEGIN

@interface CCGradientView : UIView

- (CAGradientLayer *)gradientLayer;
+ (instancetype)viewWithColors:(NSArray<UIColor*> *)colors
                       locations:(NSArray *)locations
                    startPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint
                        cornerRadius:(CGFloat)cornerRadius;
+ (instancetype)viewWithColors:(NSArray<UIColor*> *)colors
                    direction:(CCGradientViewDirection)direction
                  cornerRadius:(CGFloat)cornerRadius;

@end

NS_ASSUME_NONNULL_END
