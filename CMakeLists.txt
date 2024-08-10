cmake_minimum_required(VERSION 3.10)
project(NewGame VERSION 0.1.0 LANGUAGES C CXX)

set(ROOT "../ChaosEngineCPP")
set(PATH_LIST 
	"src"
	${ROOT}
	"${ROOT}/src"
	"${ROOT}/include"
	"${ROOT}/library"
	"${ROOT}/basic_chaos_engine"
	"${ROOT}/basic_chaos_engine/library/DirectX"
	"${ROOT}/basic_chaos_engine/library/DirectX/D2D"
)

# For Visual Studio CMake Tools
#link_directories("${ROOT}/out/build/x64-Release")
# link_directories("${ROOT}/out/build/x64-Debug")

# For VSCode CMake Tools
link_directories("${ROOT}/build/Debug")

include_directories(${PATH_LIST})

add_executable(${PROJECT_NAME} WIN32 "src/new_game.cpp")
target_link_libraries(NewGame d2d1 dwrite ChaosEngine_Static)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
