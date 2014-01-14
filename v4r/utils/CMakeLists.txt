set(UTILS_CPP 
 distributions.cpp 
 string.cpp 
 filesystemhdl.cpp
 timehdl.cpp
)
set(UTILS_H
 distributions.h 
 string.h
 filesystemhdl.h
 timehdl.h
)


IF(NOT DEFINED V4R_COMPILE_STATIC)
add_library(v4rutils SHARED ${UTILS_CPP} ${UTILS_H})
ELSE()
add_library(v4rutils STATIC ${UTILS_CPP} ${UTILS_H})
ENDIF()

target_link_libraries(v4rutils ${Boost_LIBS} ${catkin_LIBRARIES})


INSTALL(FILES ${UTILS_H} 
 DESTINATION /usr/include/v4r/utils)
INSTALL(TARGETS v4rutils
 LIBRARY DESTINATION /usr/lib/)
