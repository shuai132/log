#include "log.h"

int main() {
  LOG("log");
  LOGR("raw" LOG_LINE_END);
  LOGT("T", "msg with tag");
  LOGD("debug");
  LOGI("info");
  LOGW("warn");
  LOGE("error");
  LOGF("fatal");
  LOGV("verbose");
  return 0;
}
