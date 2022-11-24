cmake_minimum_required(VERSION 3.10)
# 项目名，会默认建立两个全局变量
# ${PROJECT_SOURCE_DIR}：本CMakeLists.txt所在的文件夹路径
# ${PROJECT_NAME}：本CMakeLists.txt的project名称
project(LERN_CMAKE)
# 使用的C++的标准
# set(CMAKE_CXX_STANDARD 14.0)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
# -lm链接math库
# lm 是link libm
# lz 是link libz
# -ldl是link dl
# -fpermissive 该选项会将不一致代码的诊断从错误降级为警告。
# -lstdc++fs 链接c++的file库
# -fPIC PIC就是position independent code,编译出的so库，没有绝对地址，全部使用相对地址，故而代码可以被加载器加载到内存的任意位置，都可以正确的执行
# -ffunction-sections 将每个函数或符号创建为一个sections 减少可执行文件大小，去掉没有用到的函数
set(CMAKE_CXX_FLAGS " -o -Wall -pthread -g -lm -ldl  -DLINUX_OS -lstdc++fs -fpermissive -pipe -fPIC -ffunction-sections ${CMAKE_CXX_FLAGS}")
# 设置变量名
set(INCLUDE_PATH ${PROJECT_SOURCE_DIR}/include)
set(SOURC_PAHT ${PROJECT_SOURCE_DIR}/src)
set(LIB_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
# 头文件包含路径
include_directories(${INCLUDE_PATH})
# 编译子目录
add_subdirectory(src)
# 获取路径下所有的.cpp/.c/.cc文件，并赋值给变量中
aux_source_directory(${PROJECT_SOURCE_DIR} SOURCE_FILE)
# 生成的可执行文件路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)
# 编译源文件，生成可执行文件len_cmake
add_executable(len_cmake ${SOURCE_FILE})
# 连接静态库
target_link_libraries(len_cmake swap)