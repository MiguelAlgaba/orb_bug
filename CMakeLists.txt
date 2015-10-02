project( ORB_BUG )

cmake_minimum_required( VERSION 2.8 )

# Define the output directories for the executables
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ORB_BUG_BINARY_DIR}/bin )

# OpenCV library
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Declare the target (an executable)
add_executable( orb_bug orb_bug.cpp )

target_link_libraries( orb_bug ${OpenCV_LIBS} )

# Set optimized building:
if( CMAKE_COMPILER_IS_GNUCXX AND NOT CMAKE_BUILD_TYPE MATCHES "Debug" )
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -mtune=native")
endif()

