//
//  ZWSingleton.h
//  DictPublishAssistant
//
//  Created by sun on 15/2/8.
//  Copyright (c) 2015年 zhuwei. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 定义单例模式类    INTERFACE_SINGLETON(类名)
 实现单例模式类    IMPLEMENTATION_SINGLETON(类名)
 */
#undef	INTERFACE_SINGLETON
#define INTERFACE_SINGLETON( __class ) \
    - (__class *)sharedInstance; \
    + (__class *)sharedInstance;

#undef	IMPLEMENTATION_SINGLETON
#define IMPLEMENTATION_SINGLETON( __class ) \
    - (__class *)sharedInstance \
    { \
        return [__class sharedInstance]; \
    } \
    + (__class *)sharedInstance \
    { \
        static dispatch_once_t once; \
        static __class * __singleton__; \
        dispatch_once( &once, ^{ __singleton__ = [[[self class] alloc] init]; } ); \
        return __singleton__; \
    }

