cmake_minimum_required(VERSION 3.10)

project(
    slonda-man 
    VERSION 1.0
)

include("$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

add_executable(${PROJECT_NAME}
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
	# Source/GUI/StackMenu.cpp
	# Source/GUI/Button.cpp
	# Source/GUI/Textbox.cpp
	# Source/GUI/Widget.cpp
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
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)

target_compile_definitions(${PROJECT_NAME} PRIVATE GLM_ENABLE_EXPERIMENTAL)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
    set(CMAKE_CXX_FLAGS_RELEASE "/Ox")
  	target_compile_options(${PROJECT_NAME} PRIVATE /W4 _CRT_SECURE_NO_WARNINGS)
else()
  	target_compile_options(${PROJECT_NAME} PRIVATE 
		-Wall -Wextra -pedantic)		
endif()

find_package(glm CONFIG REQUIRED)
find_package(SFML COMPONENTS system audio network window graphics CONFIG REQUIRED)

add_subdirectory(deps)
target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    deps
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    sfml-system sfml-audio sfml-network sfml-graphics sfml-window
    glm::glm
    glad 
)
