# Copyright: Asociación de Robótica ASROB (C) 2017;
# Authors: David Estevez, based on files by Juan G. Victores
# CopyPolicy: Released under the terms of the GNU GPL v3.0.

# reduce warning level with cmake 2.6
cmake_minimum_required(VERSION 2.6)
#cmake policies
if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

project(ASROB_HEXAKILLER)

set(BUILD_SHARED_LIBS TRUE CACHE INTERNAL "hide this!")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -frtti")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frtti")

add_definitions(-DYARP_NO_DEPRECATED_WARNINGS=ON)

### options: cpp devices
option(ENABLE_Devices "Choose if you want to compile devices" TRUE)

### options: force default
option(ENABLE_FourBarsBatteryStatus "Enable/disable compilation of FourBarsBatteryStatus device" TRUE)

option(ColorDebug_Options "Choose if you want to modify ColorDebug Options" FALSE)
if(ColorDebug_Options)
    # ColorDebug options
    option(ColorDebug_FULL_FILE "Choose if you want to compile with CD_FULL_FILE" FALSE)
    if(ColorDebug_FULL_FILE)
        add_definitions(-DCD_FULL_FILE)
    endif(ColorDebug_FULL_FILE)

    option(ColorDebug_HIDE_ERROR "Choose if you want to compile with CD_HIDE_ERROR" FALSE)
    if(ColorDebug_HIDE_ERROR)
        add_definitions(-DCD_HIDE_ERROR)
    endif(ColorDebug_HIDE_ERROR)

    option(ColorDebug_HIDE_WARNING "Choose if you want to compile with CD_HIDE_WARNING" FALSE)
    if(ColorDebug_HIDE_WARNING)
        add_definitions(-DCD_HIDE_WARNING)
    endif(ColorDebug_HIDE_WARNING)

    option(ColorDebug_HIDE_SUCCESS "Choose if you want to compile with CD_HIDE_SUCCESS" FALSE)
    if(ColorDebug_HIDE_SUCCESS)
        add_definitions(-DCD_HIDE_SUCCESS)
    endif(ColorDebug_HIDE_SUCCESS)

    option(ColorDebug_HIDE_INFO "Choose if you want to compile with CD_HIDE_INFO" FALSE)
    if(ColorDebug_HIDE_INFO)
        add_definitions(-DCD_HIDE_INFO)
    endif(ColorDebug_HIDE_INFO)

    option(ColorDebug_HIDE_DEBUG "Choose if you want to compile with CD_HIDE_DEBUG" FALSE)
    if(ColorDebug_HIDE_DEBUG)
        add_definitions(-DCD_HIDE_DEBUG)
    endif(ColorDebug_HIDE_DEBUG)
endif(ColorDebug_Options)

### Some stuff for windows (not supported yet)
#if(MSVC)
#  MESSAGE(STATUS "Running on windows")
#  set(CMAKE_DEBUG_POSTFIX "d")
#endif(MSVC)

#if(NOT CMAKE_BUILD_TYPE)
#  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
#    "Choose the type of build, recommanded options are: Debug or Release")
#endif(NOT CMAKE_BUILD_TYPE)
## Hide variable to MSVC users, since it is not needed
#if (MSVC)
#   mark_as_advanced(CMAKE_BUILD_TYPE)
#endif(MSVC)

######################

### this makes everything go in $ASROB_HEXAKILLER_DIR/lib and $ASROB_HEXAKILLER_DIR/bin
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
message(STATUS "Libraries go to ${LIBRARY_OUTPUT_PATH}")
message(STATUS "Executables go to ${EXECUTABLE_OUTPUT_PATH}")
# this doesn't happen automatically for makefiles
make_directory(${LIBRARY_OUTPUT_PATH})
make_directory(${EXECUTABLE_OUTPUT_PATH})
# and let us clean their contents on a "make clean"
##set_directory_properties(PROPERTIES LIBRARY_OUTPUT_PATH ADDITIONAL_MAKE_CLEAN_FILES)
##set_directory_properties(PROPERTIES EXECUTABLE_OUTPUT_PATH ADDITIONAL_MAKE_CLEAN_FILES)
mark_as_advanced(LIBRARY_OUTPUT_PATH EXECUTABLE_OUTPUT_PATH)
mark_as_advanced(CMAKE_BACKWARDS_COMPATIBILITY)
##########################################

# Pick up our cmake modules - they are all in the cmake subdirectory
set(ASROB_HEXAKILLER_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
# let cmake use them
list(APPEND CMAKE_MODULE_PATH ${ASROB_HEXAKILLER_MODULE_PATH})

#set_property(GLOBAL PROPERTY ASROB_HEXAKILLER_INCLUDE_DIRS)
#set_property(GLOBAL PROPERTY ASROB_HEXAKILLER_LINK_DIRS)
#set_property(GLOBAL PROPERTY ASROB_HEXAKILLER_LIBRARIES)
set(ASROB_HEXAKILLER_INCLUDE_DIRS CACHE INTERNAL "appended header dirs" FORCE)
set(ASROB_HEXAKILLER_LINK_DIRS CACHE INTERNAL "appended link dirs" FORCE)
set(ASROB_HEXAKILLER_LIBRARIES CACHE INTERNAL "appended libraries" FORCE)

# add main contents
add_subdirectory(extern)
add_subdirectory(devices)

# export our variables to a ASROB_HEXAKILLERConfig.cmake creation
set(ASROB_HEXAKILLER_LINK_DIRS ${ASROB_HEXAKILLER_LINK_DIRS} ${LIBRARY_OUTPUT_PATH})
configure_file(${CMAKE_SOURCE_DIR}/cmake/template/ASROB_HEXAKILLERConfig.cmake.in
               ${CMAKE_BINARY_DIR}/ASROB_HEXAKILLERConfig.cmake @ONLY)

# create a symbolic link to the shared directory (as contains models and may be heavy)
# If you want a deep copy, you can use the copy_directory command instead of create_symlink.
#add_custom_target(install_applications COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/share ${CMAKE_SOURCE_DIR}/../share)


# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/template/ASROB_HEXAKILLERConfigUninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/ASROB_HEXAKILLERConfigUninstall.cmake" IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/ASROB_HEXAKILLERConfigUninstall.cmake)
