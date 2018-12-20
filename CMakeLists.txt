CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
PROJECT(brainbreaks)

INCLUDE(GNUInstallDirs)
INCLUDE(FindPkgConfig)

SET(VERSION_MAJOR 0)
SET(VERSION_MINOR 1)
SET(VERSION_PATCH 0)
SET(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

pkg_check_modules(pkgs REQUIRED
	glib-2.0)

FOREACH(flag ${pkgs_CFLAGS})
	ADD_COMPILE_OPTIONS(${flag})
ENDFOREACH(flag)

ADD_COMPILE_OPTIONS(
	-g -Os -std=gnu99
	-fPIC
	-Werror -Wall -Wextra
	-Wmissing-prototypes
	-Wmissing-declarations
	-Wswitch-default
	-Wno-missing-field-initializers
	-Wno-unused-parameter
	-fvisibility=hidden)

ADD_DEFINITIONS(-DEXPORT_API=__attribute__\(\(visibility\(\"default\"\)\)\))
# Run-time buffer overflow detection
ADD_DEFINITIONS(-D_FORTIFY_SOURCE=2)

INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/src)

SET(SRCS
	src/array.c
	src/strings.c
	src/util.c)

ADD_LIBRARY(brainbreaks SHARED ${SRCS})
TARGET_LINK_LIBRARIES(brainbreaks PUBLIC ${pkgs_LDFLAGS})
SET_TARGET_PROPERTIES(brainbreaks
	PROPERTIES VERSION ${VERSION} SOVERSION ${VERSION_MAJOR} OUTPUT_NAME brainbreaks)
INSTALL(TARGETS brainbreaks LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

# Tests
ENABLE_TESTING()
FILE(GLOB tests RELATIVE "${CMAKE_SOURCE_DIR}/test" "${CMAKE_SOURCE_DIR}/test/*.c")
FOREACH(test IN LISTS tests)
	GET_FILENAME_COMPONENT(test_name ${test} NAME_WE)
	ADD_EXECUTABLE(${test_name} test/${test})
	TARGET_LINK_LIBRARIES(${test_name} PUBLIC brainbreaks)
	ADD_DEPENDENCIES(${test_name} brainbreaks)
	ADD_TEST(${test_name} ${test_name})
ENDFOREACH()

