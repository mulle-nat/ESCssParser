//
//  ESCssParser.h
//  Tests
//
//  Created by TracyYih on 13-8-23.
//  Copyright (c) 2013年 EsoftMobile.com. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, RuleType) {
    RuleTypeStyle,
    RuleTypeCharset,
    RuleTypeKeyframes,
    RuleTypeKeyframe
};

typedef NS_ENUM(NSUInteger, Flags) {
    InsideStyleSheet,
    InsideKeyframes,
    InsideRuleSet,
    InsideProperty,
    InsideValue
};


@interface ESCssParser : NSObject
{
    NSMutableDictionary*    _styleSheet;
    NSMutableDictionary *   _activeKeyframes;
    NSMutableDictionary *   _activeRuleSet;
    NSMutableString *       _activeSelector;
    NSMutableString *       _activeKeyframesName;
    NSString *              _activePropertyName;
    
    
    struct {
        RuleType type;
        Flags flag;
        int lastToken;
    } _state;
}

- (NSDictionary *)parseText:(NSString *)cssText;
- (void)cssScan:(const char *)text token:(int)token;

@end