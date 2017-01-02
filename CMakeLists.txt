cmake_minimum_required(VERSION 3.5.1)
project(SDLPodstawa.exe)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_FILES_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/cmake-build-debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_CACHEFILE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-debug")
set(SOURCE_FILES main.cpp Gra/Game.cpp Gra/Game.h Gra/InputManager.cpp Gra/InputManager.h Gra/Tekstury/TextureManager.cpp Gra/Tekstury/TextureManager.h Gra/Aktorzy/ITickable.h Gra/Aktorzy/IRenderable.h Gra/Aktorzy/IRenderable.cpp Gra/Aktorzy/ITickable.cpp Gra/Aktorzy/Actor.cpp Gra/Aktorzy/Actor.h Gra/Tekstury/Texture.cpp Gra/Tekstury/Texture.h Gra/Aktorzy/Mapa/MapTile.cpp Gra/Aktorzy/Mapa/MapTile.h Gra/Aktorzy/Mapa/GameMap.cpp Gra/Aktorzy/Mapa/GameMap.h)
add_executable(SDLPodstawa.exe ${SOURCE_FILES})

INCLUDE(FindPkgConfig)
find_package(Lua 5.2 REQUIRED)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS} . ${LUA_INCLUDE_DIR})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${LUA_LIBRARIES})