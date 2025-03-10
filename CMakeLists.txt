cmake_minimum_required(VERSION 3.28)
project(Top-Down LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)



add_executable(game src/main.cpp src/util/ResourceManager.cpp src/util/ResourceManager.h src/Game.h src/Game.cpp src/util/Input.h src/Player.h src/Player.cpp src/GameObject.h src/GameObject.cpp src/Level.h src/Level.cpp)
target_compile_features(game PRIVATE cxx_std_17)
target_link_libraries(game PRIVATE SFML::Graphics SFML::System SFML::Audio)
add_custom_command(TARGET game PRE_BUILD COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/res/ $<TARGET_FILE_DIR:game>/res)