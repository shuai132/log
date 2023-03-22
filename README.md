# log

[![Build Status](https://github.com/shuai132/LOG/workflows/build/badge.svg)](https://github.com/shuai132/LOG/actions?workflow=build)

log for C/C++ project, by wrapper and enhance `printf`.

## Features

* Support C and C++
* Single header file
* With color on Unix platform
* Auto print filename and lines
* Auto line feed by `\n`, can be replaced to `\r\n` by define `LOG_LINE_END_CRLF`
* Release mode(if defined `NDEBUG` or defined `LOG_NDEBUG`) `LOGD` will be ignored
* Support thread safe

## Usage

[example.c](example.cpp)example.c

```c
#define LOG_NOT_EXIT_ON_FATAL
#define LOG_ENABLE_THREAD_SAFE
#include "log.h"

int main() {
  LOG("log");
  LOGT("T", "msg with tag");
  LOGD("debug");
  LOGI("info");
  LOGW("warn");
  LOGE("error");
  LOGF("fatal");
  [] { LOGE("in lambda"); }();
  return 0;
}
```

Output:

```text
[*]: example.cpp:6 log
[T]: example.cpp:7 msg with tag
[D]: example.cpp:8 debug
[I]: example.cpp:9 info
[W]: example.cpp:10 [main] warn
[E]: example.cpp:11 [main] error
[!]: example.cpp:12 [main] fatal
[E]: example.cpp:13 [operator()] in lambda
```
