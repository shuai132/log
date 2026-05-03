# log

[![Build Status](https://github.com/shuai132/LOG/workflows/CI/badge.svg)](https://github.com/shuai132/LOG/actions?workflow=CI)

log for C/C++ project, by wrapper and enhance `printf`.

## Design Goals

`log` is designed for lightweight C/C++ projects, including applications,
libraries, and resource-constrained targets.

* Lightweight: one header file, `printf`-style output, and optional features
  that can be disabled at compile time.
* Low flash/code size: the default C++ DateTime implementation avoids
  `std::stringstream`, `std::put_time`, and iostream formatting. It uses
  `std::chrono`, `localtime_s`/`localtime_r` when available, and a fixed
  buffer to keep the timestamp format stable.
* Consistent checks: disabled logs and release-mode `LOGD` still compile and
  evaluate their arguments through a no-output sink. This keeps debug and
  release behavior consistent, and keeps format/argument mistakes visible at
  compile time instead of hiding arbitrary code inside `((void)0)`.
* Cross-platform: supports C and C++, Unix-like systems, Windows, Android,
  FreeRTOS-style targets, and MCU usage with feature switches.
* Library-friendly: can be used inside a library without forcing debug logs on
  downstream projects, and exposes project-level options such as
  `LOG_SHOW_DEBUG`, `LOG_SHOW_VERBOSE`, and `LOG_DISABLE_ALL`.
* Easy to customize: `L_O_G_PRINTF_CUSTOM`, `L_O_G_GET_TID_CUSTOM`, and
  `L_O_G_GET_TIME_CUSTOM` let projects provide their own output, thread id, or
  timestamp implementation.

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
