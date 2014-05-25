#pragma once
#include <QApplication>


namespace Core {
 class Application : public QApplication {
      
    public:
    Application(int argc, char* argv[]);
    int exec();
    
  };
 
}