# Copyright: Asociación de Robótica ASROB (C) 2017;
# Authors: David Estevez, based on files by Juan G. Victores
# CopyPolicy: Released under the terms of the GNU GPL v3.0.

cmake_minimum_required(VERSION 2.6)

find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS}) # deprecated
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH}) # deprecated
include(YarpPlugin) # deprecated

YARP_PREPARE_PLUGIN(FourBarsBatteryStatus
                    CATEGORY device
                    TYPE hexakiller::FourBarsBatteryStatus
                    INCLUDE FourBarsBatteryStatus.hpp
                    WRAPPER batteryWrapper)

IF (NOT SKIP_FourBarsBatteryStatus)
  # Include any directories needed for YARP
  include_directories(${YARP_INCLUDE_DIRS} ${ASROB_HEXAKILLER_INCLUDE_DIRS} ${COLOR_DEBUG_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

  yarp_add_plugin(FourBarsBatteryStatus FourBarsBatteryStatus.hpp DeviceDriverImpl.cpp IBatteryImpl.cpp RateThreadImpl.cpp)
  TARGET_LINK_LIBRARIES(FourBarsBatteryStatus ${YARP_LIBRARIES} ${ARAVIS_LIBRARIES})

  # Exporting dependencies for ASROB_HEXAKILLERConfig.cmake quite manually for now...
  set(ASROB_HEXAKILLER_INCLUDE_DIRS ${ASROB_HEXAKILLER_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} CACHE INTERNAL "appended libraries")
  yarp_install(TARGETS FourBarsBatteryStatus
             EXPORT YARP
             COMPONENT runtime
             LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
             ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR})

  yarp_install(FILES FourBarsBatteryStatus.ini
              COMPONENT runtime
              DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR})
ENDIF (NOT SKIP_FourBarsBatteryStatus)

