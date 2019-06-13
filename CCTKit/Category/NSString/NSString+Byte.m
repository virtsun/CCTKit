//
//  NSString+Byte.m
//  qualitymarket
//
//  Created by sunlantao on 2019/4/8.
//  Copyright © 2019 sunlantao. All rights reserved.
//

#import "NSString+Byte.h"

@implementation NSString(Byte)

- (size_t)byteCount{
    return bytesOfString(self);
}

static inline size_t bytesOfString(NSString * str){
    int strlength = 0;
    char* p = (char*)[str cStringUsingEncoding:NSUnicodeStringEncoding];
    for (int i=0 ; i<[str lengthOfBytesUsingEncoding:NSUnicodeStringEncoding] ;i++) {
        if (*p) {
            p++;
            strlength++;
        }
        else {
            p++;
        }
    }
    return strlength;
}

- (NSString *)subStringByByteWithIndex:(NSInteger)index suffix:(NSString *)suffix{
    
    if([self byteCount] <= index) return self;
    
    NSInteger sum = 0;    
    NSRange range;
    NSRange preRange;
    for(int i=0; i<self.length; i+=range.length){
        range = [self rangeOfComposedCharacterSequenceAtIndex:i];
        NSString *s = [self substringWithRange:range];
        sum += bytesOfString(s);
        
        if (sum == index){
            NSString *str = [self substringWithRange:NSMakeRange(0, i + 1)];
            return suffix.length > 0?[str stringByAppendingString:suffix]:str;
        }else if (sum > index){
            NSString *str = [self substringWithRange:NSMakeRange(0, i)];
            return suffix.length > 0?[str stringByAppendingString:suffix]:str;
        }
        preRange = range;
    }
    
    return self;
}

@end
