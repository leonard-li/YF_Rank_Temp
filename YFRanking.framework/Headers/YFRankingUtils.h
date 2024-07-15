//
//  YFRankingUtils.h
//  YFRanking
//
//  Created by leonard.li on 2023/4/15.
//

#import <Foundation/Foundation.h>
#import <YFRanking/Message.pbobjc.h>
#import <YFCore/YFCore.h>

NS_ASSUME_NONNULL_BEGIN

#define YFRankingLogError(frmt, ...)   LOG_MAYBE(NO,                LOG_LEVEL_DEF, YFSKLogFlagError,   0, @"排行榜", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFRankingLogWarn(frmt, ...)    LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFSKLogFlagWarning, 0, @"排行榜", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFRankingLogInfo(frmt, ...)    LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFSKLogFlagInfo,    0, @"排行榜", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFRankingLogDebug(frmt, ...)   LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFSKLogFlagDebug,   0, @"排行榜", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define YFRankingLogVerbose(frmt, ...) LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_DEF, YFSKLogFlagVerbose, 0, @"排行榜", __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

@interface YFRankingUtils : NSObject

+ (NSString *)jsonFromRankInfos:(NSArray<RankInfo *> *)rankInfos;

+ (NSString *)jsonFromUserRankInfos:(NSArray<UserRankInfo *> *)userRankInfos;

+ (NSString *)jsonFromHistoryRankInfoV2:(NSArray<HistoryRankingInfoV2 *> *)histories;

@end

NS_ASSUME_NONNULL_END
