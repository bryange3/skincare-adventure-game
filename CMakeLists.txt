cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
project(final-project)

# This tells the compiler to not aggressively optimize and
# to include debugging information so that the debugger
# can properly read what's going on.
set(CMAKE_BUILD_TYPE Debug)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Warning flags
if(MSVC)
    # warning level 3 and all warnings as errors
    add_compile_options(/W3 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wpedantic -Werror)
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# FetchContent_MakeAvailable was not added until CMake 3.14
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.x
)

# Adds Catch2 testing library
FetchContent_GetProperties(catch2)
if(NOT catch2_POPULATED)
    FetchContent_Populate(catch2)
    add_library(catch2 INTERFACE)
    target_include_directories(catch2 INTERFACE ${catch2_SOURCE_DIR}/single_include)
endif()

get_filename_component(CINDER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../" ABSOLUTE)
get_filename_component(APP_PATH "${CMAKE_CURRENT_SOURCE_DIR}/" ABSOLUTE)

include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

list(APPEND CORE_SOURCE_FILES src/core/game.cc)

list(APPEND CORE_SOURCE_FILES src/core/product.cc)

list(APPEND CORE_SOURCE_FILES src/core/product_category.cc)

list(APPEND CORE_SOURCE_FILES src/core/routine.cc)

list(APPEND CORE_SOURCE_FILES src/core/routines.cc)

list(APPEND CORE_SOURCE_FILES src/core/game_state.cc)

list(APPEND CORE_SOURCE_FILES src/core/player.cc)

list(APPEND TEST_FILES tests/skincare_game_test.cc)

list(APPEND SOURCE_FILES    ${CORE_SOURCE_FILES}
        src/visualizer/skincare_game_app.cc)

list(APPEND SOURCE_FILES    ${CORE_SOURCE_FILES}
        src/visualizer/skincare_game_canvas.cc)

FetchContent_Declare(
        gflags
        GIT_REPOSITORY https://github.com/gflags/gflags.git
        GIT_TAG        v2.2.2
)

FetchContent_GetProperties(gflags)
if(NOT gflags_POPULATED)
    FetchContent_Populate(gflags)
    add_subdirectory(${gflags_SOURCE_DIR} ${gflags_BINARY_DIR})
endif()

add_executable(skincare-game apps/skincare_game_main.cc ${CORE_SOURCE_FILES})
target_link_libraries(skincare-game PRIVATE gflags)
target_include_directories(skincare-game PRIVATE include)

set(jsoncpp_DIR "/Users/bryange/Documents/CS126/vcpkg/packages/jsoncpp_x64-osx/share/jsoncpp/")
find_package(jsoncpp CONFIG REQUIRED)
target_link_libraries(skincare-game PRIVATE jsoncpp_object jsoncpp_static)

ci_make_app(
        APP_NAME        cinder-skincare-game
        CINDER_PATH     ${CINDER_PATH}
        SOURCES apps/cinder_app_main.cc ${SOURCE_FILES}
        INCLUDES        include
        LIBRARIES       jsoncpp_object jsoncpp_static
)

ci_make_app(
        APP_NAME        cinder-skincare-test
        CINDER_PATH     ${CINDER_PATH}
        SOURCES         tests/test_main.cc ${SOURCE_FILES} ${TEST_FILES}
        INCLUDES        include
        LIBRARIES       catch2 jsoncpp_object jsoncpp_static
)

if(MSVC)
    set_property(TARGET skincare-game-test APPEND_STRING PROPERTY LINK_FLAGS " /SUBSYSTEM:CONSOLE")
endif()