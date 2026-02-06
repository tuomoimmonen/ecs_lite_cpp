cmake_minimum_required(VERSION 3.16)
project(ecs_lite_cpp VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(PROJECT_SOURCES
    src/main.cpp
    src/components/Component.cpp
    src/components/TransformComponent.cpp
    src/entity/Entity.cpp

)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# ---------------------------------------------------------------------------
# Link Libraries
# ---------------------------------------------------------------------------

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE

    )
    
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
    "src"
)

if(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE

    )

endif()


