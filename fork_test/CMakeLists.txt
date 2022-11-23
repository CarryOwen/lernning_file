cmake_minimum_required(VERSION 3.7)
#cross compile option (ON/OFF)
option(BUILD_JETSON_NANO "Whether or not to use the cross tools"  ON)

if(BUILD_JETSON_NANO)
    include(cross.cmake)
endif()

project(X-Camera)


set(CMAKE_CXX_STANDARD 14)
# -lm链接math库
# lm 是link libm
# lz 是link libz
# -ldl是link dl
# -fpermissive 该选项会将不一致代码的诊断从错误降级为警告。
# -lstdc++fs 链接c++的file库
# -fPIC PIC就是position independent code,编译出的so库，没有绝对地址，全部使用相对地址，故而代码可以被加载器加载到内存的任意位置，都可以正确的执行
# -ffunction-sections 将每个函数或符号创建为一个sections 减少可执行文件大小，去掉没有用到的函数
set(CMAKE_CXX_FLAGS " -o -Wall -pthread -g -lm -ldl  -DLINUX_OS -lstdc++fs -fpermissive -pipe -fPIC -ffunction-sections ${CMAKE_CXX_FLAGS}")


if(CMAKE_SYSTEM_PROCESSOR MATCHES arm)
    include_directories(
            ${PROJECT_SOURCE_DIR}/ThirdParty/include/zmq
            ${PROJECT_SOURCE_DIR}/ThirdParty/include
            ${PROJECT_SOURCE_DIR}/export/include
            ${PROJECT_SOURCE_DIR}/export/include/Axon
            /usr/include/opencv4
            /usr/local/cuda-10.2/targets/aarch64-linux/include/
    )
    link_directories(
            ${PROJECT_SOURCE_DIR}/export/lib/careray
            ${PROJECT_SOURCE_DIR}/export/lib
            ${PROJECT_SOURCE_DIR}/export/lib/Axon
            ${PROJECT_SOURCE_DIR}/ThirdParty/lib
            /usr/lib/aarch64-linux-gnu
            /lib/aarch64-linux-gnu
            /usr/local/cuda-10.2/targets/aarch64-linux/lib/
    )
else()
    include_directories(
        /usr/include
        /usr/include/c++/6
        /usr/local/include
    )
    link_directories(
        /usr/lib
        /usr/local/lib/
    )
endif()
# # Set zmq path
# set(ZMQ_INSTALL_DIR  /usr/local)
# include(${ZMQ_INSTALL_DIR}/lib/cmake/ZeroMQ/ZeroMQConfig.cmake)

#Open GDB debugging
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")

# add_subdirectory(test)
# add_subdirectory(pub_sub)
include_directories (Common Channel Collimator Camera Detector Generator Gyro Light Position)
aux_source_directory (Common SRC_LIST1)
aux_source_directory (Channel SRC_LIST2)
aux_source_directory (Collimator SRC_LIST3)
aux_source_directory (Camera SRC_LIST4)
aux_source_directory (Detector SRC_LIST5)
aux_source_directory (Generator SRC_LIST6)
aux_source_directory (Gyro SRC_LIST7)
aux_source_directory (Light SRC_LIST8)
aux_source_directory (Position SRC_LIST9)
aux_source_directory (Charge SRC_LIST10)
aux_source_directory (Keyboard SRC_LIST11)
aux_source_directory (WifiAndBlutooth SRC_LIST12)
add_executable(SmartAssistant Main.cpp ${SRC_LIST1} ${SRC_LIST2} ${SRC_LIST3} ${SRC_LIST4} ${SRC_LIST5} ${SRC_LIST6} ${SRC_LIST7} ${SRC_LIST8} ${SRC_LIST9} ${SRC_LIST10} ${SRC_LIST11} ${SRC_LIST12})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries(SmartAssistant zmq log4cpp stdc++fs pthread opencv_core opencv_highgui opencv_imgproc opencv_imgcodecs opencv_calib3d opencv_cudaarithm opencv_cudacodec opencv_cudaimgproc opencv_cudawarping OpenNI2 AXonLink dl Interface Algorithm Data Common Detector protobuf sqlite3 Command rt)

