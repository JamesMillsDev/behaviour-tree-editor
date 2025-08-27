cmake_minimum_required(VERSION 3.16)

project(BehaviourTreeProjects VERSION 1.0.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FetchContent module
include(FetchContent)

# Fetch nlohmann_json
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.12.0
)

# Fetch raylib
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

# Make dependencies available
FetchContent_MakeAvailable(nlohmann_json raylib)

# Add subdirectories
add_subdirectory(BehaviourTrees)
add_subdirectory(BehaviourTreeEditor)