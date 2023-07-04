#include "log.h"

int main() {
  LOG("log");
  LOGT("T", "msg with tag");
  LOGD("debug");
  LOGI("info");
  LOGW("warn");
  LOGE("error");
  LOGF("fatal");
  LOGV("verbose");
  [] { LOGE("in lambda"); }();
  return 0;
}
