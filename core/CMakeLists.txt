cmake_minimum_required(VERSION 3.10)

file(GLOB_RECURSE RENDERLAMP_CORE_HEADERS CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/*/include/*.hpp"
)

file(GLOB_RECURSE RENDERLAMP_CORE_SOURCES CONFIGURE_DEPENDS
	"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
	"${CMAKE_CURRENT_SOURCE_DIR}/*/src/*.cpp"
)

add_library(RenderLampCore SHARED
	${RENDERLAMP_CORE_HEADERS}
	${RENDERLAMP_CORE_SOURCES}
)

target_include_directories(RenderLampCore
	PUBLIC
		"${CMAKE_CURRENT_SOURCE_DIR}"
		"${CMAKE_CURRENT_SOURCE_DIR}/device/include"
		"${CMAKE_CURRENT_SOURCE_DIR}/kernels/include"
		"${CMAKE_CURRENT_SOURCE_DIR}/scene/include"
		"${CMAKE_CURRENT_SOURCE_DIR}/session/include"
)

target_compile_definitions(RenderLampCore PRIVATE RENDERLAMP_EXPORTS)

if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET RenderLampCore PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(RenderLampCore
	PUBLIC
		glm::glm
		nlohmann_json::nlohmann_json
)