cmake_minimum_required(VERSION 3.24)
project(pdb)
set(CMAKE_CXX_STANDARD 23)

# Libs
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# libpdb
add_library(pdb SHARED src/dummy.cpp src/collection/Collection.cpp src/collection/Collection.h src/collection/store/MemoryStore.cpp src/collection/store/MemoryStore.h src/collection/store/Store.cpp src/collection/store/Store.h src/Database.cpp src/Database.h src/collection/schema/Schema.h src/collection/schema/Schema.cpp)

# Testing
enable_testing()

add_executable(pdb_test test/schema/schema.test.cpp)
target_link_libraries(pdb_test GTest::gtest_main pdb)

include(GoogleTest)
gtest_discover_tests(pdb_test)