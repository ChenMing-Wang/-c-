cmake_minimum_required(VERSION 3.21)
project(image_process)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 修改clion 内存
MATH(EXPR stack_size "16*1024*1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

#QT
set(CMAKE_PREFIX_PATH E:\\qt\\5.9.5\\msvc2017_64)
find_package(Qt5Widgets)
find_package( Qt5Core)
find_package( Qt5Gui)
find_package(Qt5Multimedia)
find_package(Qt5MultimediaWidgets)
find_package(Qt5Sql)
find_package(Qt5PrintSupport)


#sqlite
#add_compile_options(-l sqlite3)
#add_executable(Q_S main.cpp sqlite3.c)
#find_package(Sql)1286

#OPENCV
set(OpenCV_DIR E:\\opencv\\opencv\\build\\x64\\vc15\\lib)
find_package(OpenCV REQUIRED)
INCLUDE_DIRECTORIES( ${OpenCV_INCLUDE_DIRS})

#halcon
INCLUDE_DIRECTORIES(G:\\develop\\halcon\\halcon-21.11.0.0-x64-win64\\HALCON-21.11-Progress\\include)
link_directories(G:\\develop\\halcon\\halcon-21.11.0.0-x64-win64\\HALCON-21.11-Progress\\lib\\x64-win64)



add_executable(image_process main.cpp widget.cpp widget.h widget.ui MyLabel.cpp MyLabel.h Image_adjust/image_adjust.cpp Image_adjust/image_adjust.h energy/energy.cpp energy/energy.h graphics/graphics.cpp graphics/graphics.h graphics.ui resource/resource.qrc graphics/graphicsview.cpp graphics/graphicsview.h graphics/graphicsscene.cpp graphics/graphicsscene.h graphics/graphicsPathItem.cpp graphics/graphicsPathItem.h)
target_link_libraries(image_process ${OpenCV_LIBS})
target_link_libraries(image_process ${CMAKE_DL_LIBS})
target_link_libraries(image_process Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Multimedia Qt5::MultimediaWidgets Qt5::Sql Qt5::PrintSupport)
target_link_libraries(image_process halcon halconcpp)