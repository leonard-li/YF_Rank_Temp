//
//  YFActivityRoomInfo.h
//  YFRanking
//
//  Created by leonard.li on 12/12/24.
//

#import <Foundation/Foundation.h>

@class ActivityRoomInfo;

NS_ASSUME_NONNULL_BEGIN

@interface YFActivityRoomInfo : NSObject

@property(nonatomic, copy) NSString *userId;

@property(nonatomic, copy) NSString *extendsInfo;

@property(nonatomic, copy) NSString *activityId;

+ (instancetype)activityRoomInfoWithInfo:(ActivityRoomInfo *)info;

@end

NS_ASSUME_NONNULL_END
