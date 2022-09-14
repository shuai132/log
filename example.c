#define LOG_NOT_EXIT_ON_FATAL
#include "log.h"

int main() {
    LOG("log");
    LOGT("T", "msg with tag");
    LOGD("debug");
    LOGI("info");
    LOGW("warn");
    LOGE("error");
    LOGF("fatal");
    return 0;
}
