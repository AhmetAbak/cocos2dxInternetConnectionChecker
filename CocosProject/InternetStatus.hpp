//
//  InternetStatus.hpp
//  SNGTileGame
//
//  Created by Ahmet Abak on 18/08/16.
//
//

#ifndef InternetStatus_hpp
#define InternetStatus_hpp

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include "Connectivity.h"
#endif
class InternetStatus
{
public:
    static bool hasInternetConnection()
    {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        cocos2d::JniMethodInfo methodInfo;
        
        if (! cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/sngict/game/connection/Connectivity", "isConnectedToInternet", "()Z")) {
            return false;
        }
        
        bool isConnected = (bool) methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        cocos2d::log( "is connected: %d", isConnected ); // not printing logs with cout in android
        return isConnected;
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        std::cout << "is connected: " << Connectivity::hasInternetConnection() << std::endl;
        return Connectivity::hasInternetConnection();
#endif
    }
    
    static bool isConnectionFast()
    {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        cocos2d::JniMethodInfo methodInfo;
        
        if (! cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/sngict/game/connection/Connectivity", "isConnectionTypeFast", "()Z")) {
            return false;
        }
        
        bool isFast = (bool) methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        cocos2d::log( "is fast: %d" , isFast);
        return isFast;
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        std::cout << "is fast: " << Connectivity::isConnectionFast() << std::endl;
        return Connectivity::isConnectionFast();
#endif
    }
    
    static bool isConnectionTypeMobile()
    {
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        cocos2d::JniMethodInfo methodInfo;
        
        if (! cocos2d::JniHelper::getStaticMethodInfo(methodInfo, "com/sngict/game/connection/Connectivity", "isConnectionTypeMobile", "()Z")) {
            return false;
        }
        
        bool isMobile = (bool) methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        cocos2d::log( "is mobile: %d" , isMobile );
        return isMobile;
#endif
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        std::cout << "is mobile: " << Connectivity::isConnectionTypeMobile() << std::endl;
        return Connectivity::isConnectionTypeMobile();
#endif
    }
    
};

#endif /* InternetStatus_hpp */
