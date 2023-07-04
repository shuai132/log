# log

[![Build Status](https://github.com/shuai132/LOG/workflows/build/badge.svg)](https://github.com/shuai132/LOG/actions?workflow=build)

log for C/C++ project, by wrapper and enhance `printf`.

## Features

* One header file
* Colors on Unix
* Print filename and lines automatically
* Line feed with `\n`, or `\r\n` with `LOG_LINE_END_CRLF`
* Ignores `LOGD` in release mode
* Support thread safe and thread id
* Support DateTime

## Usage

[example](example.cpp)

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
2023-03-29 18:11:23.479 0x1f8934140 [*]: example.cpp:4 log
2023-03-29 18:11:23.479 0x1f8934140 [T]: example.cpp:5 msg with tag
2023-03-29 18:11:23.479 0x1f8934140 [D]: example.cpp:6 debug
2023-03-29 18:11:23.479 0x1f8934140 [I]: example.cpp:7 info
2023-03-29 18:11:23.479 0x1f8934140 [W]: example.cpp:8 [main] warn
2023-03-29 18:11:23.479 0x1f8934140 [E]: example.cpp:9 [main] error
2023-03-29 18:11:23.479 0x1f8934140 [!]: example.cpp:10 [main] fatal
2023-03-29 18:11:23.479 0x1f8934140 [V]: example.cpp:11 verbose
2023-03-29 18:11:23.479 0x1f8934140 [E]: example.cpp:12 [operator()] in lambda
```
