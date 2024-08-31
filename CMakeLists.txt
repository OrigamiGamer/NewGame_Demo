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
	"${ROOT}/basic_chaos_engine/libraries"
	"${ROOT}/basic_chaos_engine/libraries/utils"
	"${ROOT}/basic_chaos_engine/libraries/utils/fftw3/api"
	"${ROOT}/basic_chaos_engine/libraries/audio"
	"${ROOT}/basic_chaos_engine/libraries/audio/OpenAL"
	"${ROOT}/basic_chaos_engine/libraries/graphics"
	"${ROOT}/basic_chaos_engine/libraries/graphics/DirectX"
	"${ROOT}/basic_chaos_engine/libraries/graphics/DirectX/D2D"
)

# For different IDE
# link_directories("${ROOT}/out/build/x64-Release")
link_directories(${PATH_LIST} "${ROOT}/out/build/x64-Debug" "${ROOT}/out/build/Debug")

include_directories(${PATH_LIST})

add_executable(${PROJECT_NAME} WIN32 "src/new_game.cpp")
target_link_libraries(NewGame d2d1 dwrite ChaosEngine_Static)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
