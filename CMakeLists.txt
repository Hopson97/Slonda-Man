cmake_minimum_required(VERSION 3.1)

project(slender-man)
#Set up the C++ flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_LIBRARIES -lstdc++fs)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCES
	Source/Main.cpp
	Source/Camera.cpp
	Source/Context.cpp
	Source/Game.cpp
	Source/GLLib/GLFunctions.cpp
	Source/Maths/Frustum.cpp
	Source/Maths/Matrix.cpp
	Source/Texture/TextureCube.cpp
	Source/Texture/Texture2D.cpp
	Source/Util/FileUtil.cpp
	Source/Util/FPSCounter.cpp
	Source/Util/Maths.cpp
	Source/Util/ToggleKey.cpp
	Source/Util/Animation.cpp
	Source/World/Slenderman.cpp
	Source/World/ObjectiveText.cpp
	Source/World/Player.cpp
	Source/World/Level.cpp
	Source/World/Entity.cpp
	Source/Shaders/Shader.cpp
	Source/Shaders/ShaderLoader.cpp
	Source/Terrain/TerrainGenerator.cpp
	Source/Terrain/Terrain.cpp
	Source/GUI/StackMenu.cpp
	Source/GUI/Button.cpp
	Source/GUI/Textbox.cpp
	Source/GUI/Widget.cpp
	Source/Input/Keyboard.cpp
	Source/Model/Model.cpp
	Source/Model/TexturedModel.cpp
	Source/Model/Generator.cpp
	Source/Model/Mesh.cpp
	Source/Model/ModelLoader.cpp
	Source/ResourceManager/ResourceHolder.cpp
	Source/States/StatePlaying.cpp
	Source/Renderer/PrimitiveRenderer.cpp
	Source/Renderer/SfmlRenderer.cpp
	Source/Renderer/SkyboxRenderer.cpp
	Source/Renderer/PostFXRenderer.cpp
	Source/Renderer/MasterRenderer.cpp
	Source/Renderer/EntityRenderer.cpp
	Source/Renderer/TerrainRenderer.cpp
	Source/Glad/glad.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

#Find the SFML package
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED audio network graphics window system)
#For using GLAD (or opengl), Unix requires an additional '-ldl' flag
SET(ADDITIONAL_LINK_FLAGS)
if(UNIX)
    list(APPEND ADDITIONAL_LINK_FLAGS dl)
endif(UNIX)
find_package(Threads)
target_link_libraries(${PROJECT_NAME} Threads::Threads ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${ADDITIONAL_LINK_FLAGS})
