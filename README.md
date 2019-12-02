# LOG

[![Build Status](https://github.com/shuai132/LOG/workflows/build/badge.svg)](https://github.com/shuai132/LOG/actions?workflow=build)

LOG for C/C++ project, by wrapper and enhance `printf`.

## Features

* Support C and C++
* Single header file
* With color on Unix platform
* Auto print filename and lines
* Auto line feed by `\n`, can be replaced to `\r\n` by define `LOG_LINE_END_CRLF`
* Release mode(if defined `NDEBUG`) `LOGD` will be ignored

## Usage

example.c
```c
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
```

Output:
```text
LOG
example.c: DEBUG
example.c: LOGI
TAG: LOGT
ERROR: example.c: main: 8: ERROR
```
