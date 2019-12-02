/**
 * 方便打印日志
 *
 * 宏    含义    作用                       颜色
 * LOG:  LOG    等效于printf并换行         默认色
 * LOGT: TAG    第一个参数为tag            默认色
 * LOGI: INFO   带有文件名信息             默认色
 * LOGE: ERROR  错误信息 会有ERROR:前缀     红色
 * LOGD: DEBUG  debug模式（NDEBUG未定义时） 黄色
 * 为了保证输出顺序 错误也使用stdout而不是stderr
 */

#pragma once

#ifdef __cplusplus
#include <cstdio>
#include <cstring>
#include <cstdlib>
#else
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif

#ifdef  LOG_LINE_END_CRLF
#define LOG_LINE_END        "\r\n"
#else
#define LOG_LINE_END        "\n"
#endif

#ifndef _WIN32
#define LOG_COLOR_RED_S     "\033[31m"
#define LOG_COLOR_RED_E     "\033[31m"  LOG_LINE_END
#define LOG_COLOR_YELLOW_S  "\033[33m"
#define LOG_COLOR_YELLOW_E  "\033[33m"  LOG_LINE_END
#define LOG_BASE_FILENAME   (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#else
#define LOG_COLOR_RED_S
#define LOG_COLOR_RED_E     LOG_LINE_END
#define LOG_COLOR_YELLOW_S
#define LOG_COLOR_YELLOW_E  LOG_LINE_END
#define LOG_BASE_FILENAME   (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#endif

#define LOG(fmt, ...)           do{ printf(fmt LOG_LINE_END, ##__VA_ARGS__); } while(0)
#define LOGT(tag, fmt, ...)     do{ printf(tag ": " fmt LOG_LINE_END, ##__VA_ARGS__); } while(0)
#define LOGI(fmt, ...)          do{ printf("%s: " fmt LOG_LINE_END, LOG_BASE_FILENAME, ##__VA_ARGS__); } while(0)
#define LOGE(fmt, ...)          do{ printf(LOG_COLOR_RED_S "ERROR: %s: %s: %d: " fmt LOG_COLOR_RED_E, \
                                    LOG_BASE_FILENAME, __func__, __LINE__, ##__VA_ARGS__); \
                                } while(0)

#ifdef NDEBUG
#define LOGD(fmt, ...)          ((void)0)
#else
#define LOGD(fmt, ...)          do{ printf(LOG_COLOR_YELLOW_S "%s: " fmt LOG_COLOR_YELLOW_E, LOG_BASE_FILENAME, ##__VA_ARGS__); } while(0)
#endif

#define FATAL(fmt, ...)         do{ LOGE(fmt, ##__VA_ARGS__); exit(EXIT_FAILURE); } while(0)
