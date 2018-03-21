cmake_minimum_required (VERSION 2.8.11)
project (O3X100)

find_package(PCL 1.7 REQUIRED COMPONENTS common)
find_package(OpenCV 3 REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

include_directories(
  ${PCL_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  )

find_library(IFM3D_CAMERA ifm3d_camera)
find_library(IFM3D_FRAMEGRABBER ifm3d_framegrabber)
find_library(IFM3D_IMAGE ifm3d_image)
find_library(PCL_COMMON pcl_common)
find_library(BOOST_SYSTEM boost_system)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(O3X100 O3X100.cpp)
target_link_libraries(O3X100
  ${BOOST_SYSTEM}
  ${PCL_COMMON}
  ${IFM3D_CAMERA}
  ${IFM3D_FRAMEGRABBER}
  ${IFM3D_IMAGE}
  ${OpenCV_LIBS}
  )
