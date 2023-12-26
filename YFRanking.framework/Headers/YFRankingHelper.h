//
//  YFRankingHelper.h
//  YFRanking
//
//  Created by leonard.li on 2023/4/15.
//

#import <Foundation/Foundation.h>
#import <YFRanking/RankInfo.pbobjc.h>
#import <YFRanking/FetchActivityResp.pbobjc.h>
#import <YFRanking/ActivityRoomInfo.pbobjc.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFRankingHelper : NSObject

/// 单例
@property (class, nonatomic, readonly) YFRankingHelper *defaultHelper;
/// 包名
@property (copy, nonatomic) NSString *bundleId;

//- (void)initWithGeo:(NSString *)userGeo;

/// 获取排行榜数据
/// @param rankingId 排行榜ID
/// @param geo 用户地区信息
/// @param start 开始位置/名次
/// @param end 结束位置/名次
- (void)getRankingWithId:(NSString *)rankingId
                 withGeo:(NSString *)geo
               withStart:(uint32_t)start
                 withEnd:(uint32_t)end
              completion:(nullable void(^)(NSError * _Nullable error, NSArray<RankInfo *> * _Nullable rankInfos))completion;

/// 提交排行榜数据
/// @param rankingId 排行榜ID
/// @param userId 用户ID, 如为空则从YFAuthHelper.defaultHelper.userInfo中获取
/// @param geo 用户地区信息
/// @param scores 排行榜成绩(3个), 成绩类型为[整形]
/// @param extendInfo 扩展信息, 开发者可自定义该字段信息, 例如用户名/头像等
- (void)submitRankingWithId:(NSString *)rankingId
                 withUserId:(NSString *)userId
                    withGeo:(NSString *)geo
                 withScores:(NSArray<NSNumber *> *)scores
             withExtendInfo:(NSString *)extendInfo
                 completion:(nullable void(^)(NSError * _Nullable error))completion;

/// 获取活动数据
/// @param activityId 活动ID
- (void)getActivitysWithId:(NSString *)activityId
                completion:(nullable void(^)(NSError * _Nullable error, FetchActivityResp * _Nullable activityInfo))completion;

/// 加入活动
/// @param activityId 活动ID
/// @param userId 用户ID, 如为空则从YFAuthHelper.defaultHelper.userInfo中获取
/// @param weight 权重
/// @param endTime 结束时间, 以秒为单位的时间戳(10位), 用来清理房间
/// @param active 活跃和非活跃 0.非活跃 1.活跃
/// @param tag 分组标签, 相同标签的为一组
- (void)joinActivityWithId:(NSString *)activityId
                withUserId:(NSString *)userId
                withWeight:(uint32_t)weight
               withEndTime:(NSTimeInterval)endTime
                withActive:(NSInteger)active
                   withTag:(NSString *)tag
                completion:(nullable void(^)(NSError * _Nullable error, NSString * _Nullable roomId))completion;

/// 获取活动房间数据
/// @param activityId 活动ID
/// @param roomId 房间ID
- (void)getActivityRoomWithId:(NSString *)activityId
                   withRoomId:(NSString *)roomId
                   completion:(nullable void(^)(NSError * _Nullable error, NSArray<ActivityRoomInfo *> * _Nullable roomInfo))completion;

/// 提交活动数据
/// @param activityId 活动ID
/// @param userId 用户ID, 如为空则从YFAuthHelper.defaultHelper.userInfo中获取
/// @param roomId 房间ID
/// @param extendInfo 扩展信息, 开发者可自定义该字段信息, 例如用户名/头像等
/// @param progress 活动进度，大于等于该值时，用户不能再加入该房间
/// @param active 活跃和非活跃 0.非活跃 1.活跃
/// @param tag 分组标签, 相同标签的为一组
- (void)submitActivityWithId:(NSString *)activityId
                  withUserId:(NSString *)userId
                  withRoomId:(NSString *)roomId
              withExtendInfo:(NSString *)extendInfo
                withProgress:(NSInteger)progress
                  withActive:(NSInteger)active
                     withTag:(NSString *)tag
                  completion:(nullable void(^)(NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
