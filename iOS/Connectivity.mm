//
//  Connectivity.m
//  SNGTileGame
//
//  Created by Ahmet Abak on 18/08/16.
//
//
#include "Reachability.h"
#include "Connectivity.h"
#include <CoreTelephony/CTTelephonyNetworkInfo.h>
bool Connectivity::hasInternetConnection()
{
    return [[Reachability reachabilityForInternetConnection] isReachable];
}

bool Connectivity::isConnectionTypeMobile()
{
    Reachability *reachability = [Reachability reachabilityForInternetConnection];
    [reachability startNotifier];
    
    NetworkStatus status = [reachability currentReachabilityStatus];
    
    if(status == NotReachable)
    {
        //No internet
        return false;
    }
    else if (status == ReachableViaWiFi)
    {
        //WiFi
        return false;
    }
    else if (status == ReachableViaWWAN) 
    {
        //3G. LTE. ...
        return true;
    }
    return false;
}

bool Connectivity::isConnectionFast()
{
    if (!hasInternetConnection()) {
        return false;
    }
    CTTelephonyNetworkInfo *telephonyInfo = [CTTelephonyNetworkInfo new];
    NSString *radioAccessTechnology = telephonyInfo.currentRadioAccessTechnology;
    
        if ([radioAccessTechnology isEqualToString:CTRadioAccessTechnologyGPRS]) {
            return false;
        } else if ([radioAccessTechnology isEqualToString:CTRadioAccessTechnologyEdge]) {
            return false;
        } else if ([radioAccessTechnology isEqualToString:CTRadioAccessTechnologyWCDMA]) {
            return false;
        } else if ([radioAccessTechnology isEqualToString:CTRadioAccessTechnologyHSDPA]) {
            return true;
        } else if ([radioAccessTechnology isEqualToString:CTRadioAccessTechnologyHSUPA]) {
            return true;
        } else if ([radioAccessTechnology isEqualToString:CTRadioAccessTechnologyCDMA1x]) {
            return false;
        } else if ([radioAccessTechnology isEqualToString:CTRadioAccessTechnologyCDMAEVDORev0]) {
            return true;
        } else if ([radioAccessTechnology isEqualToString:CTRadioAccessTechnologyCDMAEVDORevA]) {
            return true;
        } else if ([radioAccessTechnology isEqualToString:CTRadioAccessTechnologyCDMAEVDORevB]) {
            return true;
        } else if ([radioAccessTechnology isEqualToString:CTRadioAccessTechnologyeHRPD]) {
            return true;
        } else if ([radioAccessTechnology isEqualToString:CTRadioAccessTechnologyLTE]) {
            return true;
        }
        return true;
}