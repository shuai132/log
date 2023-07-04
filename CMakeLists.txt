cmake_minimum_required(VERSION 3.1)

project(LOG)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall)

add_compile_definitions(
        LOG_NOT_EXIT_ON_FATAL
        LOG_SHOW_VERBOSE
        ANDROID_STANDALONE
)

# default
add_executable(log_example_c example.c)
add_executable(log_example example.cpp)

# custom define
add_executable(log_example_disable_thread_safe example.cpp)
target_compile_definitions(log_example_disable_thread_safe PRIVATE "-DLOG_DISABLE_THREAD_SAFE")

add_executable(log_example_disable_thread_id example.cpp)
target_compile_definitions(log_example_disable_thread_id PRIVATE "-DLOG_DISABLE_THREAD_ID")

add_executable(log_example_disable_date_time example.cpp)
target_compile_definitions(log_example_disable_date_time PRIVATE "-DLOG_DISABLE_DATE_TIME")

add_executable(log_example_disable_ts_ti_dt example.cpp)
target_compile_definitions(log_example_disable_ts_ti_dt PRIVATE
        "-DLOG_DISABLE_THREAD_SAFE"
        "-DLOG_DISABLE_THREAD_ID"
        "-DLOG_DISABLE_DATE_TIME"
        )
