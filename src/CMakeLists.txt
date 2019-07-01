
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

foreach(p
    CMP0071 # 3.10: Let AUTOMOC and AUTOUIC process GENERATED files
CMP0074
    )
  if(POLICY ${p})
    cmake_policy(SET ${p} NEW)
  endif()
endforeach()


project(MathWorks C CXX)
if(WIN32)
set(CMAKE_CXX_STANDARD 17)
else()
set(CMAKE_CXX_STANDARD 17)
endif()

#Use solution folders.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Allow the developer to select if Dynamic or Static libraries are built
OPTION (BUILD_SHARED_LIBS "Build Shared Libraries" OFF)
OPTION (BUILD_GOOGLE_TESTS "Build Google Tests" OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
EXECUTE_PROCESS(COMMAND gcc -dumpversion OUTPUT_VARIABLE GCC_VERSION)
#MESSAGE(STATUS "in this :${GCC_VERSION}" )
if((${GCC_VERSION} MATCHES [5][.][1-9][.0-9]*) OR (${GCC_VERSION} MATCHES [6-9]+[.][0-9][.0-9]*) ) 
#MESSAGE(STATUS "in regex :${GCC_VERSION}" )
add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
endif()
endif()

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if (MSVC)
  add_definitions (/D "_CRT_SECURE_NO_WARNINGS" /D "_SCL_SECURE_NO_WARNINGS" /D "SOCK_ERRORS" /D "NOMINMAX" /D "_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS")
endif (MSVC)
add_definitions(-DXSD_CXX11)
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/external
)

add_subdirectory(apps)
add_subdirectory(core)

enable_testing()

if (BUILD_GOOGLE_TESTS)
	add_subdirectory(external/googletest)
	add_subdirectory(tests)
endif()