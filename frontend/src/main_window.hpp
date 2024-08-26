#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include "shell/ui_widget.hpp"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public shell::UiWidget<QMainWindow, Ui::MainWindow>
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow() override;
};

#endif    //  MAIN_WINDOW_HPP
