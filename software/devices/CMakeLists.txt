# Copyright: Asociación de Robótica ASROB (C) 2017;
# Authors: David Estevez, based on files by Juan G. Victores
# CopyPolicy: Released under the terms of the GNU GPL v3.0.

cmake_minimum_required(VERSION 2.6)

IF (ENABLE_Devices)

  find_package(YARP REQUIRED)
  include_directories(${YARP_INCLUDE_DIRS})
  list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})  
  include(YarpPlugin)

  add_subdirectory(FourBarsBatteryStatus)
  add_subdirectory(TestBatteryStatus)

  # Exporting dependencies for ASROB_HEXAKILLERConfig.cmake quite manually for now...
  set(ROBOTICSLAB_YARP_DEVICES_INCLUDE_DIRS ${ASROB_HEXAKILLER_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "appended libraries")

ENDIF (ENABLE_Devices)
