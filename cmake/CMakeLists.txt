cmake_minimum_required(VERSION 3.5)

project("CM2 Reference")


if (NOT DEFINED CMAKE_HOST_WIN32)
	message(FATAL_ERROR "CM2 Reference currently only works on Windows")
endif()


set(ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/..")


function(add_library_gen TARGET PATH)

	get_filename_component(PATH_ABS ${PATH} ABSOLUTE)

	get_filename_component(PATH_DIRECTORY ${PATH_ABS} DIRECTORY)
	get_filename_component(PATH_NAME_WE ${PATH_ABS} NAME_WE)
	get_filename_component(PATH_NAME ${PATH_ABS} NAME)

	set(PATH_LIB "${PATH_DIRECTORY}/${PATH_NAME_WE}.lib")

	add_custom_command(
		OUTPUT "${PATH_LIB}"
		COMMAND ${ROOT_DIR}/tools/libgen.cmd ${PATH_NAME} x86
		WORKING_DIRECTORY "${PATH_DIRECTORY}"
		DEPENDS "${PATH_ABS}"
		COMMENT "Generating library files from ${PATH_NAME}"
		VERBATIM
	)

	add_custom_target(${PATH_NAME_WE}.lib DEPENDS "${PATH_LIB}")

	add_library("${TARGET}" INTERFACE)
	target_link_libraries("${TARGET}" INTERFACE "${PATH_LIB}")

endfunction()


add_library_gen(faktum "${ROOT_DIR}/bin/faktum/faktum.dll")
add_library_gen(cm2 "${ROOT_DIR}/bin/cm2/cm2.dll")

target_include_directories(faktum INTERFACE "${ROOT_DIR}/include")
target_include_directories(cm2 INTERFACE "${ROOT_DIR}/include")

target_link_libraries(cm2 INTERFACE faktum)
