//
//  NSString+Byte.h
//  qualitymarket
//
//  Created by sunlantao on 2019/4/8.
//  Copyright © 2019 sunlantao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString(Byte)


- (size_t)byteCount;

//从字符串中截取指定字节数
- (NSString *)subStringByByteWithIndex:(NSInteger)index suffix:(NSString *)suffix;

@end

NS_ASSUME_NONNULL_END
