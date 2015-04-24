PROJECT(githublbp)
SET(CMAKE_BUILD_TYPE Release)
CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )
FIND_PACKAGE( OpenCV REQUIRED )

ADD_EXECUTABLE(lbp_video lbp_video.cpp lbp.cpp histogram.cpp)
ADD_EXECUTABLE(lbp_image lbp_features.cpp lbp.cpp histogram.cpp)

TARGET_LINK_LIBRARIES(lbp_video ${OpenCV_LIBS})
TARGET_LINK_LIBRARIES(lbp_image ${OpenCV_LIBS})
