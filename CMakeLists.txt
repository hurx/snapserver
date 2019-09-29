cmake_minimum_required(VERSION 2.8)
project (snapshot)

include_directories("/home/hrx/mycpath/ffmpeg")
include_directories("/usr/local/ffmpeg/FFmpeg-4.2.1-build/include")
link_directories("/home/hrx/mycpath/ffmpeg")
link_directories("/usr/local/ffmpeg/FFmpeg-4.2.1-build/lib")
add_executable(snapshot snapshot.cpp)
target_link_libraries(snapshot ${Boost_LIBRARIES})
target_link_libraries(snapshot 
	${CMAKE_THREAD_LIBS_INIT}
	snap
    	avcodec
    	avformat
    	swscale
    	swresample
    	avutil
	)

