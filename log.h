/**
 * 方便打印日志
 * 为了保证输出顺序 都使用stdout而不是stderr
 *
 * 可配置项
 * LOG_LINE_END_CRLF
 * LOG_FOR_MCU
 * LOG_NDEBUG
 * LOG_NOT_EXIT_ON_FATAL
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

#ifdef LOG_NOT_EXIT_ON_FATAL
#define LOG_EXIT_PROGRAM()
#else
#ifdef LOG_FOR_MCU
#define LOG_EXIT_PROGRAM()      do{ for(;;); } while(0)
#else
#define LOG_EXIT_PROGRAM()      exit(EXIT_FAILURE)
#endif
#endif

#define LOG_BASE_FILENAME \
    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : \
    strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define LOG_WITH_COLOR
#if defined(_WIN32) || defined(LOG_FOR_MCU)
#undef LOG_WITH_COLOR
#endif

#ifdef LOG_WITH_COLOR
#define LOG_COLOR_RED       "\033[31m"
#define LOG_COLOR_GREEN     "\033[32m"
#define LOG_COLOR_YELLOW    "\033[33m"
#define LOG_COLOR_BLUE      "\033[34m"
#define LOG_COLOR_CARMINE   "\033[35m"
#define LOG_COLOR_CYAN      "\033[36m"
#define LOG_COLOR_DEFAULT
#define LOG_COLOR_END       "\033[m"
#else
#define LOG_COLOR_RED
#define LOG_COLOR_GREEN
#define LOG_COLOR_YELLOW
#define LOG_COLOR_BLUE
#define LOG_COLOR_CARMINE
#define LOG_COLOR_CYAN
#define LOG_COLOR_DEFAULT
#define LOG_COLOR_END
#endif

#define LOG_END                 LOG_COLOR_END LOG_LINE_END

#define LOG(fmt, ...)           do{ printf(LOG_COLOR_GREEN "[V]: " fmt LOG_END, ##__VA_ARGS__); } while(0)
#define LOGT(tag, fmt, ...)     do{ printf(LOG_COLOR_BLUE "[" tag "]: " fmt LOG_END, ##__VA_ARGS__); } while(0)
#define LOGI(fmt, ...)          do{ printf(LOG_COLOR_YELLOW "[I]: %s: " fmt LOG_END, LOG_BASE_FILENAME, ##__VA_ARGS__); } while(0)
#define LOGW(fmt, ...)          do{ printf(LOG_COLOR_CARMINE "[W]: %s: %s: %d: " fmt LOG_END, \
                                    LOG_BASE_FILENAME, __func__, __LINE__, ##__VA_ARGS__); \
                                } while(0)
#define LOGE(fmt, ...)          do{ printf(LOG_COLOR_RED "[E]: %s: %s: %d: " fmt LOG_END, \
                                    LOG_BASE_FILENAME, __func__, __LINE__, ##__VA_ARGS__); \
                                } while(0)
#define FATAL(fmt, ...)         do{ printf(LOG_COLOR_CYAN "[F]: %s: %s: %d: " fmt LOG_END, \
                                    LOG_BASE_FILENAME, __func__, __LINE__, ##__VA_ARGS__); \
                                    LOG_EXIT_PROGRAM(); \
                                } while(0)

#if defined(NDEBUG) || defined(LOG_NDEBUG)
#define LOGD(fmt, ...)          ((void)0)
#else
#define LOGD(fmt, ...)          do{ printf(LOG_COLOR_DEFAULT "[D]: %s: " fmt LOG_END, LOG_BASE_FILENAME, ##__VA_ARGS__); } while(0)
#endif
