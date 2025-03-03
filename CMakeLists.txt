# CMakeList.txt : CMake project for Commander, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Commander")

# Add source to this project's executable.
add_executable ( Commander )

target_sources ( Commander PRIVATE 
	source/Application.cpp
	"source/CommandPanel.cpp"
	"source/CommandButton.cpp"   
	"source/Command.cpp" 
	"source/Config.cpp"
)

# Add wxWidgets
set ( wxBUILD_SHARED off )
add_subdirectory ( external/wxWidgets-3.2.6 )
target_link_libraries ( Commander PRIVATE wx::core wx::base )

# Add nlohmann json
add_subdirectory ( external/json-develop )
target_link_libraries ( Commander PRIVATE nlohmann_json)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Commander PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
