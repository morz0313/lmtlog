/*
 * @Copyright    : Copyright xxx Inc.
 * @Author       : morz
 * @Date         : xxxx-xx-xx xx:xx:xx
 * @Description  : xxx
 */

#include "rotatelog.h"

#include <spdlog/common.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog.h>

namespace lmtlog {

RotateLog::RotateLog(string logger_name, string filename, size_t max_file_size,
                     size_t max_files) {
  rotating_logger_ = spdlog::rotating_logger_mt(logger_name, filename,
                                                max_file_size, max_files);

  rotating_logger_->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%-5l] %s:%# %v");

  rotating_logger_->flush_on((spdlog::level::level_enum)kEnumDebug);
}

RotateLog::~RotateLog() { ShutDown(); }

LevelEnum RotateLog::GetLevel() { return (LevelEnum)rotating_logger_->level(); }

void RotateLog::SetLevel(LevelEnum lvl) {
  rotating_logger_->set_level((spdlog::level::level_enum)lvl);
}

void RotateLog::Debug(source_loc loc, const char *fmt, ...) {
  va_list argptr;
  va_start(argptr, fmt);
  Log(loc, LevelEnum::kEnumDebug, fmt, argptr);
  va_end(argptr);
}

void RotateLog::Info(source_loc loc, const char *fmt, ...) {
  va_list argptr;
  va_start(argptr, fmt);
  Log(loc, LevelEnum::kEnumInfo, fmt, argptr);
  va_end(argptr);
}

void RotateLog::Warn(source_loc loc, const char *fmt, ...) {
  va_list argptr;
  va_start(argptr, fmt);
  Log(loc, LevelEnum::kEnumWarn, fmt, argptr);
  va_end(argptr);
}

void RotateLog::Error(source_loc loc, const char *fmt, ...) {
  va_list argptr;
  va_start(argptr, fmt);
  Log(loc, LevelEnum::kEnumErr, fmt, argptr);
  va_end(argptr);
}

void RotateLog::Log(source_loc loc, LevelEnum lvl, const char *fmt,
                    va_list args) {
  size_t size = 1024;
  char *buffer = new char[size];

  while (1) {
    va_list args_copy;
    va_copy(args_copy, args);
    int n = vsnprintf(buffer, size, fmt, args_copy);
    va_end(args_copy);

    if (-1 < n && static_cast<size_t>(n) < size) {
      string s(buffer);
      rotating_logger_->log(loc, (spdlog::level::level_enum)lvl, s.c_str());
      delete[] buffer;
      return;
    }

    size = (-1 < n) ? n + 1 : size * 2;
    delete[] buffer;
    buffer = new char[size];
  }
}

void RotateLog::ShutDown() { spdlog::shutdown(); }
}  // namespace lmtlog
