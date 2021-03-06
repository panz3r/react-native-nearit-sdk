/*
 * Copyright (c) 2017 Mattia Panzeri <mattia.panzeri93@gmail.com>
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>
#import <React/RCTUtils.h>

#import <UserNotifications/UserNotifications.h>
#import <CoreLocation/CoreLocation.h>
#import <NearIT/NearIT.h>

#import "RNNearItBackgroundQueue.h"
#import "RNNotificationsQueue.h"

@interface RNNearIt : RCTEventEmitter <RCTBridgeModule, UNUserNotificationCenterDelegate, CLLocationManagerDelegate, NITManagerDelegate>

@property int listeners;

#if !TARGET_OS_TV
    + (void)registerForRemoteNotifications;
    + (void)application:(UIApplication* _Nonnull)application didFinishLaunchingWithOptions:(NSDictionary* _Nullable)launchOptions;
    + (void)didRegisterForRemoteNotificationsWithDeviceToken:(NSData* _Nonnull)deviceToken;
    + (void)didReceiveRemoteNotification:(NSDictionary* _Nonnull) userInfo;
    + (void)didReceiveLocalNotification:(UILocalNotification* _Nonnull) notification;
    + (void)didReceiveNotificationResponse:(UNNotificationResponse* _Nonnull) response withCompletionHandler:(void (^ _Nonnull)())completionHandler;
    + (void)didReceiveNotification:(NSDictionary* _Nonnull)userInfo fromUserAction:(BOOL)fromUserAction;
    + (void)application:(UIApplication* _Nonnull)application performFetchWithCompletionHandler:(void (^_Nonnull)(UIBackgroundFetchResult))completionHandler;
    + (void)disableDefaultRangingNotifications;
#endif

@end

