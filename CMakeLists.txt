cmake_minimum_required(VERSION 3.5)

project(LOG)

set(CMAKE_CXX_STANDARD 11)
add_compile_options(-Wall)

add_compile_definitions(
        L_O_G_NOT_EXIT_ON_FATAL
        L_O_G_SHOW_VERBOSE
        ANDROID_STANDALONE
)

# default
add_executable(log_example example.cpp)
add_executable(log_example_c example.c)

# custom define
add_executable(log_example_disable_thread_safe example.cpp)
target_compile_definitions(log_example_disable_thread_safe PRIVATE "-DL_O_G_DISABLE_THREAD_SAFE")

add_executable(log_example_disable_thread_id example.cpp)
target_compile_definitions(log_example_disable_thread_id PRIVATE "-DL_O_G_DISABLE_THREAD_ID")

add_executable(log_example_disable_date_time example.cpp)
target_compile_definitions(log_example_disable_date_time PRIVATE "-DL_O_G_DISABLE_DATE_TIME")

add_executable(log_example_disable_ts_ti_dt example.cpp)
target_compile_definitions(log_example_disable_ts_ti_dt PRIVATE
        "-DL_O_G_DISABLE_THREAD_SAFE"
        "-DL_O_G_DISABLE_THREAD_ID"
        "-DL_O_G_DISABLE_DATE_TIME"
        )

add_executable(log_example_custom example.cpp)
target_compile_definitions(log_example_custom PRIVATE "-DL_O_G_PRINTF_CUSTOM=my_printf")
