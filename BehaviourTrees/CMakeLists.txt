cmake_minimum_required(VERSION 3.16)

project(BehaviourTrees VERSION 1.0.0)

option(ENABLE_RAYLIB "Enable Raylib support" OFF)
option(ENABLE_GLM "Enable GLM support" OFF)

if(ENABLE_GLM)
    # Include FetchContent module
    include(FetchContent)

    # Fetch nlohmann_json
    FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1
    )

    FetchContent_MakeAvailable(glm)
endif()

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# nlohmann_json is available from parent via FetchContent

# Create the shared library
add_library(BehaviourTrees SHARED)

target_compile_definitions(BehaviourTrees 
    PRIVATE 
        DLL_EXPORT
)

if(ENABLE_RAYLIB)
    target_compile_definitions(BehaviourTrees 
        PRIVATE 
            RAYLIB_SUPPORT_ENABLED
    )
endif()

if(ENABLE_GLM)
    target_compile_definitions(BehaviourTrees 
        PRIVATE 
            GLM_SUPPORT_ENABLED
    )
endif()

# Automatically find all source files
file(GLOB_RECURSE BEHAVIOUR_TREES_SOURCES
    "src/*.cpp"
)

# Automatically find all header files (for IDE support)
file(GLOB_RECURSE BEHAVIOUR_TREES_HEADERS
    "include/*.h"
    "src/*.h"      # Private headers in src/
)

# Add sources
target_sources(BehaviourTrees PRIVATE
    ${BEHAVIOUR_TREES_SOURCES}
    ${BEHAVIOUR_TREES_HEADERS}  # For IDE project view
)

# Set include directories
target_include_directories(BehaviourTrees
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

if(ENABLE_GLM)
    target_link_libraries(BehaviourTrees
        PRIVATE
            glm
    )
endif()

# Link dependencies
# Note: Using PRIVATE because nlohmann_json is header-only and fetched via FetchContent
# Users of this library will get nlohmann_json through the config file dependency
target_link_libraries(BehaviourTrees
    PRIVATE
        nlohmann_json::nlohmann_json
)

if(ENABLE_RAYLIB)
    target_link_libraries(BehaviourTrees
        PRIVATE
            raylib
    )
endif()