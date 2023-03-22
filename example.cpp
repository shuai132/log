#define LOG_NOT_EXIT_ON_FATAL
#define LOG_ENABLE_THREAD_SAFE
#include "log.h"

int main() {
  LOG("log");
  LOGT("T", "msg with tag");
  LOGD("debug");
  LOGI("info");
  LOGW("warn");
  LOGE("error");
  LOGF("fatal");
  [] { LOGE("in lambda"); }();
  return 0;
}
