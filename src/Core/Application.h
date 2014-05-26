#pragma once
#include <QApplication>
#include <QJsonObject>

namespace Core
{
    
class MainWindow;
class Application : public QApplication
{

public:
    Application ( int argc, char* argv[] );
    int exec();

signals:
    void configurationReloaded();
    
protected:
    void loadConfig();
    void readConfig();
    void saveConfig();
    void loadDefaultConfig();
    
private:
    MainWindow *mainWindow;
    
    QJsonObject videoConfiguration;
    QJsonObject soundConfiguration;
};

} // namespace Core