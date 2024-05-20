cmake_minimum_required(VERSION 3.22)
project(TouHouProject_Ru_koto)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(CMAKE_CXX_STANDARD 17)

FILE(GLOB_RECURSE MAIN "src/Application.cpp")

FILE(GLOB_RECURSE APP_HEADER "src/Application/*.h")
FILE(GLOB_RECURSE APP_SOURCE "src/Application/*cpp")
FILE(GLOB_RECURSE APP_HPP "src/Application/*.hpp")

FILE(GLOB_RECURSE FN_HEADER "src/Application/FN/*.h")
FILE(GLOB_RECURSE FN_SOURCE "src/Application/FN/*.cpp")
FILE(GLOB_RECURSE FN_HPP "src/Application/FN/*.hpp")

FILE(GLOB_RECURSE TWOBOT_HEADER "src/server/twobot/*.h")
FILE(GLOB_RECURSE TWOBOT_SOURCE "src/server/twobot/*.cpp")
FILE(GLOB_RECURSE TWOBOT_HPP "src/server/twobot/*.hpp")

# 将源代码添加到此项目的可执行文件。
add_executable (TouHouProject_Ru_koto 
	${MAIN}
	${APP_HEADER} ${APP_SOURCE} ${APP_HPP}
	${FN_HEADER} ${FN_SOURCE} ${FN_HPP}
	${TWOBOT_HEADER} ${TWOBOT_SOURCE} ${TWOBOT_HPP}
	)

add_library(TwoBot STATIC
        src/server/twobot.hh
        src/server/twobot.cc
        src/server/apiset.cc
	)

target_include_directories(TwoBot PUBLIC src/server/)

add_subdirectory(lib)
target_link_libraries(TwoBot PUBLIC nlohmann_json::nlohmann_json brynet httplib::httplib)
target_compile_definitions(TwoBot PUBLIC _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING)


# Find our pre-installed DPP package (using FindDPP.cmake).
find_package(DPP REQUIRED)
 
# Include the DPP directories.
target_include_directories(TouHouProject_Ru_koto PRIVATE ${DPP_INCLUDE_DIR})

target_link_libraries(TouHouProject_Ru_koto ${DPP_LIBRARIES} TwoBot)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TouHouProject_Ru_koto PROPERTY CXX_STANDARD 20)
endif()
