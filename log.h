/**
 * 方便打印日志
 *
 * 宏    含义    作用
 * LOG:  LOG    等效于printf并换行
 * LOGT: TAG    第一个参数为tag
 * LOGI: INFO   带有文件名信息
 * LOGE: ERROR  错误信息 会有ERROR:前缀 输出为红色
 * LOGD: DEBUG  debug模式(NDEBUG未定义)以LOGI输出 release模式无输出
 * 为了保证输出顺序 错误也使用stdout而不是stderr
 */

#pragma once

#ifdef __cplusplus
#include <cstdio>
#include <cstring>
#else
#include <stdio.h>
#include <string.h>
#endif

// Truncates the full __FILE__ path, only displaying the basename
#define __FILENAME__ \
    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define LOG(fmt, ...)           do{ printf(fmt "\n", ##__VA_ARGS__); } while(0)
#define LOGT(tag, fmt, ...)     do{ printf(tag ": " fmt "\n", ##__VA_ARGS__); } while(0)
#define LOGI(fmt, ...)          do{ printf("%s: " fmt "\n", __FILENAME__, ##__VA_ARGS__); } while(0)
#define LOGE(fmt, ...)          do{ printf("\033[31mERROR: %s: %s: %d: " fmt "\n\033[m", \
                                    __FILENAME__, __func__, __LINE__, ##__VA_ARGS__); \
                                } while(0)

#ifdef NDEBUG
#define LOGD(fmt, ...)  ((void)0)
#else
#define LOGD(fmt, ...)  LOGI(fmt, ##__VA_ARGS__)
#endif
