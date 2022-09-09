# LOG

[![Build Status](https://github.com/shuai132/LOG/workflows/build/badge.svg)](https://github.com/shuai132/LOG/actions?workflow=build)

LOG for C/C++ project, by wrapper and enhance `printf`.

## Features

* Support C and C++
* Single header file
* With color on Unix platform
* Auto print filename and lines
* Auto line feed by `\n`, can be replaced to `\r\n` by define `LOG_LINE_END_CRLF`
* Release mode(if defined `NDEBUG` or defined `LOG_NDEBUG`) `LOGD` will be ignored

## Usage

example.c
```c
#define LOG_NOT_EXIT_ON_FATAL
#include "log.h"

int main() {
    LOG("log");
    LOGT("T", "msg with tag");
    LOGD("debug");
    LOGI("info");
    LOGW("warn");
    LOGE("error");
    FATAL("fatal error");
    return 0;
}
```

Output:
```text
[*]: log
[T]: msg with tag
[D]: example.c: debug
[I]: example.c: info
[W]: example.c: main: 9: warn
[E]: example.c: main: 10: error
[!]: example.c: main: 11: fatal error
```
