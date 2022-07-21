/*
 * @Copyright    : Copyright xxx Inc.
 * @Author       : morz
 * @Date         : xxxx-xx-xx xx:xx:xx
 * @Description  : xxx
 */

#ifndef CATEGORY_H_
#define CATEGORY_H_

#include "rotatelog.h"

using spdlog::source_loc;

namespace lmtlog {
class Category {
 public:
  /**
   * @description: 创建全局lmt日志回滚对象
   *               日志名：lmtlog
   *               文件名：./log/lmtlog.log
   *               文件大小：5Mb
   *               文件个数：1
   * @param {*}
   * @return {*} 返回全局回滚日志对象
   */
  static RotateLog &GetLmtLog();
};
}  // namespace lmtlog

#define LOG_DEBUG(fmt, ...)            \
  lmtlog::Category::GetLmtLog().Debug( \
      source_loc(__FILE__, __LINE__, SPDLOG_FUNCTION), fmt, ##__VA_ARGS__)

#define LOG_INFO(fmt, ...)            \
  lmtlog::Category::GetLmtLog().Info( \
      source_loc(__FILE__, __LINE__, SPDLOG_FUNCTION), fmt, ##__VA_ARGS__)

#define LOG_WARN(fmt, ...)            \
  lmtlog::Category::GetLmtLog().Warn( \
      source_loc(__FILE__, __LINE__, SPDLOG_FUNCTION), fmt, ##__VA_ARGS__)

#define LOG_ERROR(fmt, ...)            \
  lmtlog::Category::GetLmtLog().Error( \
      source_loc(__FILE__, __LINE__, SPDLOG_FUNCTION), fmt, ##__VA_ARGS__)

#endif  // CATEGORY_H_
