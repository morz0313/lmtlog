/*
 * @Copyright    : Copyright xxx Inc.
 * @Author       : morz
 * @Date         : xxxx-xx-xx xx:xx:xx
 * @Description  : xxx
 */

#ifndef ROTATELOG_H_
#define ROTATELOG_H_

#include <spdlog/common.h>
#include <spdlog/logger.h>

#include <cstdarg>
#include <memory>
#include <string>

using spdlog::source_loc;
using std::shared_ptr;
using std::string;

namespace lmtlog {
typedef enum LevelEnum {
  // kEnumTrace = 0,
  kEnumDebug = 1,
  kEnumInfo = 2,
  kEnumWarn = 3,
  kEnumErr = 4,
  // kEnumCritical
} LevelEnum;

class RotateLog {
 public:
  /**
   * @description: 回滚日志对象构造函数
   *               默认打印级别：info
   *               打印格式：[xxxx-xx-xx xx:xx:xx.xxx] [level] log msg
   * @param {string} logger_name 日志对象名称
   * @param {string} filename 日志文件名称
   * @param {size_t} max_file_size 日志文件大小
   * @param {size_t} max_files 回滚最大文件个数
   * @return {*}
   */
  RotateLog(string logger_name, string filename, size_t max_file_size,
            size_t max_files);

  ~RotateLog();

  LevelEnum GetLevel();

  void SetLevel(LevelEnum lvl);

  void Debug(source_loc loc, const char *fmt, ...);

  void Info(source_loc loc, const char *fmt, ...);

  void Warn(source_loc loc, const char *fmt, ...);

  void Error(source_loc loc, const char *fmt, ...);

  /**
   * @description: 释放所有spdlog资源，并删除注册表中的所有记录器
   *               这是可选的（只有在使用windows+异步日志时才是必需的）
   * @param {*}
   * @return {*}
   */
  void ShutDown();

 private:
  shared_ptr<spdlog::logger> rotating_logger_;

  void Log(source_loc loc, LevelEnum lvl, const char *fmt, va_list args);
};
}  // namespace lmtlog
#endif  // ROTATELOG_H_
