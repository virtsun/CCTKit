//
//  CCGradientView.m
//  qualitymarket
//
//  Created by sunlantao on 2019/1/17.
//  Copyright © 2019 sunlantao. All rights reserved.
//

#import "CCGradientView.h"

@implementation CCGradientView

+ (Class)layerClass{
    return [CAGradientLayer class];
}

- (CAGradientLayer *)gradientLayer{
    return (CAGradientLayer *)self.layer;
}


+(instancetype)viewWithColors:(NSArray<UIColor *> *)colors locations:(NSArray *)locations startPoint:(CGPoint)startPoint endPoint:(CGPoint)endPoint cornerRadius:(CGFloat)cornerRadius{
    CCGradientView *view = [CCGradientView new];
    view.gradientLayer.colors = colors;
    view.gradientLayer.startPoint = startPoint;
    view.gradientLayer.endPoint = endPoint;
    view.gradientLayer.locations = locations;
    view.layer.cornerRadius = cornerRadius;
    return view;
}

+ (instancetype)viewWithColors:(NSArray<UIColor*> *)colors
                     direction:(CCGradientViewDirection)direction
                  cornerRadius:(CGFloat)cornerRadius{
    
    CGPoint startPoint, endPoint;
    
    switch (direction) {
        case kkCCGradientViewDirectionHorizonal:
            startPoint = CGPointMake(0, 0);
            endPoint = CGPointMake(1, 0);
            break;
        case kkCCGradientViewDirectionHorizonalReverse:
            startPoint = CGPointMake(1, 0);
            endPoint = CGPointMake(0, 0);
            break;
        case kkCCGradientViewDirectionVertical:
            startPoint = CGPointMake(0, 0);
            endPoint = CGPointMake(0, 1);
            break;
        case kkCCGradientViewDirectionVerticalReverse:
            startPoint = CGPointMake(0, 1);
            endPoint = CGPointMake(0, 0);
            break;

        default:
            break;
    }
    
    return [self viewWithColors:colors locations:@[@(0), @(1)] startPoint:startPoint endPoint:endPoint cornerRadius:cornerRadius];
}

@end
