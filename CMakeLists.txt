cmake_minimum_required(VERSION 3.14)

project(whee
    VERSION 1.0.0
    DESCRIPTION "testing the binding of h5wasm with tatami"
    LANGUAGES CXX C
)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  tatami 
  GIT_REPOSITORY https://github.com/LTLA/tatami
  GIT_TAG 2dc49a3cc71907eb276de6fecb70fe6f6e01a59a
)
FetchContent_MakeAvailable(tatami)

FetchContent_Declare(
  h5wasm
  GIT_REPOSITORY https://github.com/LTLA/h5wasm-cmake-demo
  GIT_TAG 8c5ebc8c7a747d9120e8a6fe8358e5d6c27d38e9
)
FetchContent_MakeAvailable(h5wasm)

add_executable(test test.cpp)

target_link_libraries(test h5wasm_cpp tatami)

set_target_properties(test PROPERTIES
    LINK_FLAGS "--bind -s ALLOW_MEMORY_GROWTH=1 -s USE_ZLIB=1 -s FORCE_FILESYSTEM=1 -s 'EXPORTED_RUNTIME_METHODS=[\"FS\"]'"
)
