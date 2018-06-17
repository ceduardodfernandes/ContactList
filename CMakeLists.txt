cmake_minimum_required(VERSION 3.0)

project(contacts)

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/ui_console.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/data.cpp
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/src/app.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/contact.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/data.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/ui_console.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/ui_interface.hpp
)

add_executable(contacts ${SOURCE})

install(TARGETS contacts DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/bin/)