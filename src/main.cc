/*
 * @Copyright    : Copyright xxx Inc.
 * @Author       : morz
 * @Date         : xxxx-xx-xx xx:xx:xx
 * @Description  : xxx
 */

#include <iostream>

#include "category.h"
#include "rotatelog.h"

using lmtlog::Category;

int main(int, char**) {
  Category::GetLmtLog().SetLevel(lmtlog::kEnumDebug);

  LOG_DEBUG("this is a debug msg!");
  LOG_INFO("this is a info msg!");
  LOG_WARN("this is a warn msg!");
  LOG_ERROR("this is a error msg!");

  return 0;
}
