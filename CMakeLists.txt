cmake_minimum_required(VERSION 3.20)
project(lab LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(wxWidgets REQUIRED COMPONENTS core base)

include(${wxWidgets_USE_FILE})

add_executable(lab main.cpp)

target_link_libraries(lab ${wxWidgets_LIBRARIES})

if(MINGW)
    set_target_properties(lab PROPERTIES WIN32_EXECUTABLE TRUE)
endif()
