#include "log.h"

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
