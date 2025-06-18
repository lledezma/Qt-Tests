cmake_minimum_required(VERSION 3.19)
project(Qt-Tests LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Sql Test)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(Qt-Tests
    main.cpp
    database.h
    database.cpp
    databasetest.h
    databasetest.cpp
)

target_link_libraries(Qt-Tests
    PRIVATE
        Qt::Core
        Qt::Sql
        Qt::Test
)
target_link_libraries(Qt-Tests PRIVATE Qt6::Core)

include(GNUInstallDirs)

install(TARGETS Qt-Tests
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
