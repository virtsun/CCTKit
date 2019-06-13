//
//  macro.h
//  Moline
//
//  Created by l.t.zero on 2019/3/9.
//  Copyright © 2019 sunlantao. All rights reserved.
//

#ifndef macro_h
#define macro_h

#define SingletonProperty(Class, propterty, block)\
- (Class *)propterty{\
if (!_##propterty){\
do{block;}while(0);\
}\
return _##propterty;\
}\


#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)

#define AttributedStringKey(key) NSAttributedStringKey const key = @#key
#define AttributedStringKeyValue(key, value) NSAttributedStringKey const key = @#value


#define SP(Class, propterty, block) SingletonProperty(Class, propterty, block)

#define PropertyDeclareNonStrong(Class, name) @property (nonatomic, strong) Class *name;
#define PropertyDeclareNonWeak(Class, name) @property (nonatomic, weak) Class *name;
#define PropertyDeclareNonCopy(Class, name) @property (nonatomic, copy) Class *name;
#define PropertyDeclareNonAssign(Class, name) @property (nonatomic, assign) Class *name;
#define PropertyDeclareNonBaseAssign(Class, name) @property (nonatomic, assign) Class name;

#define AdjustmentContentInsetDisable(obj) \
if (@available(iOS 11.0, *)){\
obj.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;\
}\

#define NSURLString(url) [NSURL URLWithString:url]

#define ValidateString(str) (![str isKindOfClass:[NSNull class]] && str.length >0)
#define StringSafe(x, placeholder) ValidateString(x)?x:placeholder

#define Tag(str) (NSInteger)str

#define CGRectClipInsets(frame, top, left, bottom, right) \
CGRectMake(CGRectGetMinX(frame) + left, CGRectGetMinY(frame) + top, CGRectGetWidth(frame) - left - right, CGRectGetHeight(frame) - top - bottom)

#define ImageNamed(name) [UIImage imageNamed:image]


#define TextFieldInsets(ttf,top, left, bottom, right) \
[ttf setValue:@(top) forKey:@"paddingTop"];\
[ttf setValue:@(left) forKey:@"paddingLeft"];\
[ttf setValue:@(bottom) forKey:@"paddingBottom"];\
[ttf setValue:@(right) forKey:@"paddingRight"];


#endif /* macro_h */
