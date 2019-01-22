cmake_minimum_required(VERSION 3.12)

project(FirstPersonRaycaster)


## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(FirstPersonRaycaster src/main.cpp src/Camera.cpp src/KeyboardMovementController.cpp src/Map.cpp src/MouseCameraController.cpp src/Object.cpp src/RaycastRenderer.cpp include/Camera.hpp include/KeyboardMovementController.hpp include/Map.hpp include/MouseCameraController.hpp include/Object.hpp include/RaycastRenderer.hpp)

target_link_libraries(FirstPersonRaycaster m sfml-graphics sfml-audio)