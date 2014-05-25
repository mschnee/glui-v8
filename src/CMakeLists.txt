# Point to our own cmake modules
set(CMAKE_MODULE_PATH 
  ${CMAKE_MODULE_PATH} 
  ${CMAKE_SOURCE_DIR}/src/.CMakeModules
)

if (DEFINED ENV{QTDIR})
    set(CMAKE_PREFIX_PATH $ENV{QTDIR} ${CMAKE_PREFIX_PATH})
endif() 
# Some QT things.
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find SDL2
find_package(OpenGL	REQUIRED)
find_package(GLEW 	REQUIRED)
find_package(V8		REQUIRED)
find_package(Qt5Core	REQUIRED)
find_package(Qt5Widgets	REQUIRED)
find_package(Qt5OpenGL	REQUIRED)

include_directories(
  ${OPENGL_INCLUDE_DIR} 
  ${GLEW_INCLUDE_DIR} 
  ${Qt5Core_INCLUDES}
  ${Qt5Widgets_INCLUDES}
  ${Qt5OpenGl_INCLUDES}
)

set(INCLUDE_FILES
  # Core Namespace
  Core/Application.h
  
  # UI namespace
  Ui/Window.h
)

set(SOURCE_FILES
  main.cpp
  
  #Core Namespace
  Core/Application.cpp
  
  # UI namespace
  Ui/Window.cpp
)

# Add global definitions
add_definitions("-Wall")
list( APPEND CMAKE_CXX_FLAGS 
  "-std=c++11 ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs"
  )

add_executable(app-glui-v8 ${SOURCE_FILES})
qt5_use_modules(app-glui-v8 Core Widgets OpenGL)
target_link_libraries(app-glui-v8 ${OPENGL_gl_LIBRARY} ${GLEW_LIBRARY} Qt5::Widgets)


