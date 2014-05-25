#include "Application.h"
#include <exception>

/**
 * Default Constructor
 */
Core::Application::Application(int argc, char* argv[]) : QApplication(argc, argv) {
  
}

int Core::Application::exec() {
  return QApplication::exec();
}