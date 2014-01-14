set(SOURCE_CPP 
 checkerboard.cpp
)

set(SOURCE_H 
 checkerboard.h

)
add_library(v4rcheckerboard SHARED ${SOURCE_H} ${SOURCE_CPP})
target_link_libraries(v4rcheckerboard  ${OpenCV_LIBS} ${catkin_LIBRARIES})
add_subdirectory(example)
