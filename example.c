#include "log.h"

int main() {
    LOG("LOG");
    LOGD("DEBUG");
    LOGI("LOGI");
    LOGT("TAG", "LOGT");
    LOGE("ERROR");
    //FATAL("FATAL");
    return 0;
}
