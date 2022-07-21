/*
 * @Copyright    : Copyright xxx Inc.
 * @Author       : morz
 * @Date         : xxxx-xx-xx xx:xx:xx
 * @Description  : xxx
 */

#include "category.h"

#include <string>

#include "rotatelog.h"

using std::string;

namespace lmtlog {
static RotateLog *lmtlog_ = nullptr;
RotateLog &Category::GetLmtLog() {
  if (nullptr == lmtlog_) {
    string logger = "lmtlog";
    string file_name = "./log/lmtlog.log";
    size_t file_size = 1024 * 1024 * 5;
    size_t file_num = 1;
    lmtlog_ = new RotateLog(logger, file_name, file_size, file_num);
  }
  return *lmtlog_;
}
}  // namespace lmtlog
