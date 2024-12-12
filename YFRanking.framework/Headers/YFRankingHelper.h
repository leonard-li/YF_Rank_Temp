//
//  YFRankingHelper.h
//  YFRanking
//
//  Created by leonard.li on 2023/4/15.
//

#import <Foundation/Foundation.h>
#import <YFRanking/Message.pbobjc.h>
#import <YFRanking/YFActivityRoomInfo.h>

NS_ASSUME_NONNULL_BEGIN

@interface YFRankingHelper : NSObject

/// 单例
@property (class, nonatomic, readonly) YFRankingHelper *defaultHelper;
/// 业务标识
@property (copy, nonatomic) NSString *bid;

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

/// 根据用户Id获取对应榜单中的名次
/// @param rankingIds 排行榜ID集合
/// @param userId 用户id, 如为空则从YFAuthHelper.defaultHelper.userInfo中获取
/// @param geo 用户地区信息, 非必填, 全球榜不需要
- (void)getRankingWithId:(NSArray<NSString *> *)rankingIds
              withUserId:(NSString *)userId
                 withGeo:(NSString *)geo
              completion:(nullable void(^)(NSError * _Nullable error, NSArray<UserRankInfo *> * _Nullable rankInfos))completion;

/// 获取历史前三的榜单信息
/// @param rankingId 排行榜ID
/// @param geo 用户地区信息
- (void)getTopRanking:(NSString *)rankingId
              withGeo:(NSString *)geo
            completion:(nullable void(^)(NSError * _Nullable error, NSArray<HistoryRankingInfoV2 *> * _Nullable histories))completion;

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
/// @param extendInfo 用户扩展信息，包括用户的name，icon等
/// @param progress 活动进度，大于等于该值时，用户不能再加入该房间
/// @param roomId 房间ID
/// @param score 用于需要缓存前3的活动需要的分数
- (void)joinActivityWithId:(NSString *)activityId
                withUserId:(NSString *)userId
                withWeight:(uint32_t)weight
               withEndTime:(NSTimeInterval)endTime
                withActive:(NSInteger)active
                   withTag:(NSString *)tag
            withExtendInfo:(NSString *)extendInfo
              withProgress:(uint32_t)progress
                withRoomId:(NSString *)roomId
                withScore:(uint64_t)score
                completion:(nullable void(^)(NSError * _Nullable error, NSString * _Nullable roomId))completion ;

/// 获取活动房间数据
/// @param activityId 活动ID
/// @param roomId 房间ID
- (void)getActivityRoomWithId:(NSString *)activityId
                   withRoomId:(NSString *)roomId
                   completion:(nullable void(^)(NSError * _Nullable error, NSArray<ActivityRoomInfo *> * _Nullable roomInfo))completion;

/// 获取活动房间数据 -- 和上面的相比，不一样的是返回的数据
/// @param activityId 活动ID
/// @param roomId 房间ID
- (void)getActivityRoomWithIdV2:(NSString *)activityId
                     withRoomId:(NSString *)roomId
                     completion:(nullable void(^)(NSError * _Nullable error, NSArray<YFActivityRoomInfo *> * _Nullable roomInfos))completion;

/// 提交活动数据
/// @param activityId 活动ID
/// @param userId 用户ID, 如为空则从YFAuthHelper.defaultHelper.userInfo中获取
/// @param roomId 房间ID
/// @param extendInfo 扩展信息, 开发者可自定义该字段信息, 例如用户名/头像等
/// @param progress 活动进度，大于等于该值时，用户不能再加入该房间
/// @param active 活跃和非活跃 0.非活跃 1.活跃
- (void)submitActivityWithId:(NSString *)activityId
                  withUserId:(NSString *)userId
                  withRoomId:(NSString *)roomId
              withExtendInfo:(NSString *)extendInfo
                withProgress:(NSInteger)progress
                  withActive:(NSInteger)active
                  completion:(nullable void(^)(NSError * _Nullable error))completion;

/// 获取历史前三的活动信息
/// @param activityId 活动ID
- (void)getTopActivity:(NSString *)activityId
            completion:(nullable void(^)(NSError * _Nullable error, NSArray<HistoryRankingInfo *> * _Nullable histories))completion;

@end

NS_ASSUME_NONNULL_END
