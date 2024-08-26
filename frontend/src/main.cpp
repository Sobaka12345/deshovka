#include "main_window.hpp"

#include <QApplication>
#include <QFile>
#include <QProxyStyle>
#include <QSettings>

struct Style : public QProxyStyle
{};

int main(int argc, char** argv)
{
    QCoreApplication::setOrganizationName("MustLove");
    QCoreApplication::setOrganizationDomain("mustlove.com");
    QCoreApplication::setApplicationName("deshovka");

    QApplication app(argc, argv);

    {
        app.setStyle(new Style);

        QFile file(":/style/application.qss");
        file.open(QFile::ReadOnly);
        app.setStyleSheet(QLatin1String{ file.readAll() });
    }

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
