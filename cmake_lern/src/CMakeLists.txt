project(swap)
# 子目录可以编译成库的形式，供上层的调用，也可以和上层一起编译
aux_source_directory(${PROJECT_SOURCE_DIR} SRC_FILES)
# 将.cpp/.c/.cc文件生成.a静态库
# 注意，库文件名称通常为libxxx.so，在这里只要写xxx即可
# add_library(库文件名称 STATIC 文件)中间加STATIC 即为静态库，不加为动态库
add_library(${PROJECT_NAME} STATIC ${SRC_FILES})
# 包含路径
include_directories(${INCLUDE_PATH})
# 指定静态库&动态库输出路径
set(LIBRARY_OUTPUT_PATH ${LIB_OUTPUT_PATH})