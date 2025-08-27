cmake_minimum_required(VERSION 3.16)

project(BehaviourTreeEditor VERSION 1.0.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dependencies are available from parent via FetchContent
# nlohmann_json and raylib are already fetched

# Try to find the installed BehaviourTrees library first
find_package(BehaviourTrees QUIET)

if(NOT BehaviourTrees_FOUND)
    # If not found as installed package, use the local target
    if(TARGET BehaviourTrees)
        message(STATUS "Using local BehaviourTrees target")
        set(BEHAVIOUR_TREES_TARGET BehaviourTrees)
    else()
        message(FATAL_ERROR "BehaviourTrees library not found")
    endif()
else()
    message(STATUS "Found installed BehaviourTrees library")
    set(BEHAVIOUR_TREES_TARGET BehaviourTrees::BehaviourTrees)
endif()

# Automatically find all source files
file(GLOB_RECURSE EDITOR_SOURCES
    "src/*.cpp"
)

# Automatically find all header files (for IDE support)
file(GLOB_RECURSE EDITOR_HEADERS
    "src/*.h"
)

# Create executable
add_executable(BehaviourTreeEditor ${EDITOR_SOURCES} ${EDITOR_HEADERS})

target_include_directories(BehaviourTreeEditor
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

# Link libraries
target_link_libraries(BehaviourTreeEditor PRIVATE
    ${BEHAVIOUR_TREES_TARGET}
    nlohmann_json::nlohmann_json
    raylib
)

# Set properties
set_target_properties(BehaviourTreeEditor PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)