#include "log.h"

// test hex
#include "hex_test.ipp"

int main() {
  LOG("log");
  LOGT("T", "msg with tag");
  LOGD("debug");
  LOGI("info");
  LOGW("warn");
  LOGE("error");
  LOGF("fatal");
  LOGV("verbose");

  LOGR("raw");
  LOGLN();
  LOGRLN("raw");

  test_hex();

  return 0;
}
