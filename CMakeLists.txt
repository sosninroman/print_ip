cmake_minimum_required(VERSION 3.2)

project(print_ip VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

file(GLOB PRINT_IP_H
        "${PROJECT_SOURCE_DIR}/*.h"
        )

file(GLOB PRINT_IP_SRC
        "${PROJECT_SOURCE_DIR}/*.cpp"
        )
		
add_executable(print_ip ${PRINT_IP_SRC} ${PRINT_IP_H} )

set(CMAKE_CXX_STANDARD 14)

set_target_properties(print_ip PROPERTIES
  CXX_STANDARD_REQUIRED ON
  CXX_STANDARD 14
  COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT sosninroman92@gmail.com)

include (CPack)

enable_testing()

add_test(NAME test_cli COMMAND test_cli)
