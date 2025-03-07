# log

[![Build Status](https://github.com/shuai132/LOG/workflows/CI/badge.svg)](https://github.com/shuai132/LOG/actions?workflow=CI)

log for C/C++ project, by wrapper and enhance `printf`.

## Features

* One header file
* Colors on Unix
* Print filename and lines automatically
* Line feed with `\n`, or `\r\n` with `L_O_G_LINE_END_CRLF`
* Ignores `LOGD` in release mode
* Support thread safe and thread id
* Support DateTime

## Usage

[example](example.cpp)

```c++
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
2023-09-14 23:32:23.197 229765 [*]: example.cpp:4 log
2023-09-14 23:32:23.198 229765 [T]: example.cpp:5 msg with tag
2023-09-14 23:32:23.198 229765 [D]: example.cpp:6 debug
2023-09-14 23:32:23.198 229765 [I]: example.cpp:7 info
2023-09-14 23:32:23.198 229765 [W]: example.cpp:8 [main] warn
2023-09-14 23:32:23.198 229765 [E]: example.cpp:9 [main] error
2023-09-14 23:32:23.198 229765 [!]: example.cpp:10 [main] fatal
2023-09-14 23:32:23.198 229765 [V]: example.cpp:11 verbose
2023-09-14 23:32:23.198 229765 [E]: example.cpp:12 [operator()] in lambda
```
