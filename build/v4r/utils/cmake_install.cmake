# Install script for directory: /home/armuser/ros/rosbuild_src/v4r_libraries/v4r/utils

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "RelWithDebInfo")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/include/v4r/utils/distributions.h;/usr/include/v4r/utils/string.h;/usr/include/v4r/utils/filesystemhdl.h;/usr/include/v4r/utils/timehdl.h")
FILE(INSTALL DESTINATION "/usr/include/v4r/utils" TYPE FILE FILES
    "/home/armuser/ros/rosbuild_src/v4r_libraries/v4r/utils/distributions.h"
    "/home/armuser/ros/rosbuild_src/v4r_libraries/v4r/utils/string.h"
    "/home/armuser/ros/rosbuild_src/v4r_libraries/v4r/utils/filesystemhdl.h"
    "/home/armuser/ros/rosbuild_src/v4r_libraries/v4r/utils/timehdl.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  IF(EXISTS "$ENV{DESTDIR}/usr/lib/libv4rutils.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/libv4rutils.so")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/usr/lib/libv4rutils.so"
         RPATH "")
  ENDIF()
  list(APPEND CPACK_ABSOLUTE_DESTINATION_FILES
   "/usr/lib/libv4rutils.so")
FILE(INSTALL DESTINATION "/usr/lib" TYPE SHARED_LIBRARY FILES "/home/armuser/ros/rosbuild_src/v4r_libraries/lib/libv4rutils.so")
  IF(EXISTS "$ENV{DESTDIR}/usr/lib/libv4rutils.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/usr/lib/libv4rutils.so")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/usr/lib/libv4rutils.so")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

