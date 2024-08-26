cmake_minimum_required(VERSION 3.15.4)
project(deshovka)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#add_subdirectory(backend)
add_subdirectory(frontend)

add_custom_target(conan SOURCES conanfile.py configure_linux_default.sh configure_windows_default.bat)
source_group(config FILES conanfile.py configure_linux_default.sh configure_windows_default.bat)
