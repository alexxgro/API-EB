cmake_minimum_required(VERSION 3.15)
project(API)

set(CMAKE_CXX_STANDARD 14)

#set(CMAKE_C_FLAGS "-Wall -Wextra -Wpedantic -Werror -Wconversion-null -Wctor-dtor-privacy -Wnon-virtual-dtor -Wdelete-non-virtual-dtor -Wliteral-suffix -Wnarrowing -Wreorder -Wnoexcept -Wstrict-null-sentinel -Wno-non-template-friend -Wold-style-cast -Woverloaded-virtual -Wno-pmf-conversions -Wsign-promo -Wmaybe-uninitialized -Wcast-align -Wchar-subscripts -Wparentheses -Wuninitialized -Wundef -Wsign-conversion -Wlogical-op -Wno-virtual-move-assign")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -Werror -Wconversion-null -Wctor-dtor-privacy -Wnon-virtual-dtor -Wdelete-non-virtual-dtor -Wliteral-suffix -Wnarrowing -Wreorder -Wnoexcept -Wstrict-null-sentinel -Wno-non-template-friend -Wold-style-cast -Woverloaded-virtual -Wno-pmf-conversions -Wsign-promo -Wmaybe-uninitialized -Wcast-align -Wchar-subscripts -Wparentheses -Wuninitialized -Wundef -Wsign-conversion -Wlogical-op -Wno-virtual-move-assign")

#add_executable(API src/main.cpp)

#add_subdirectory(lib)
#add_subdirectory(test)
add_subdirectory(src)