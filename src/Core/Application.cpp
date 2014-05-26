#include "Application.h"
#include <exception>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QByteArray>
#include <QDebug>

#include "MainWindow.h"
/**
 * Default Constructor
 */
Core::Application::Application(int argc, char* argv[]) : QApplication(argc, argv) {
    loadDefaultConfig();
    mainWindow = new MainWindow();
    mainWindow->show();
    
}

int Core::Application::exec() {
  return QApplication::exec();
}


void Core::Application::loadDefaultConfig()
{
    QFile defaultConfigFile(":/defaultConfig.json");
    defaultConfigFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonObject defaultConfig = QJsonDocument::fromJson(
            defaultConfigFile.readAll()
        ).object();
    
    videoConfiguration = defaultConfig["Video"].toObject();
    soundConfiguration = defaultConfig["Sound"].toObject();
}

void Core::Application::loadConfig()
{

}

void Core::Application::readConfig()
{

}

void Core::Application::saveConfig()
{

}
