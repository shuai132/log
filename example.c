#define LOG_NOT_EXIT_ON_FATAL
#include "log.h"

int main() {
#ifdef LOG_LINE_END_AUTO
    LOG("log");
    LOGT("T", "msg with tag");
    LOGD("debug");
    LOGI("info");
    LOGW("warn");
    LOGE("error");
    LOGF("fatal");
#else
    LOG("log\r\n");
    LOGT("T", "msg with tag\r\n");
    LOGD("debug\r\n");
    LOGI("info\r\n");
    LOGW("warn\r\n");
    LOGE("error\r\n");
    LOGF("fatal\r\n");
#endif
    return 0;
}
