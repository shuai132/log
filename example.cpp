#include "log.h"
#include <cstdarg>

// test hex
#include "hex_test.ipp"

#ifdef L_O_G_PRINTF_CUSTOM
int my_printf(const char *fmt, ...) {
  va_list vl;
  int ret;

  va_start(vl, fmt);
  char buffer[80];
  ret = vsnprintf(buffer, sizeof(buffer), fmt, vl);
  printf("%s", buffer);
  va_end(vl);

  return ret;
}
#endif

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
  [] { LOGE("in lambda"); }();

  LOGR("raw");
  LOGLN();
  LOGRLN("raw");

  test_hex();

  return 0;
}
