#include "Core/Application.h"

int main(int argc, char *argv[]) {
  Core::Application *app = new Core::Application(argc, argv);
  return app->exec();
}
  