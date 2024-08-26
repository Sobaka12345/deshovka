#include "main_window.hpp"

#include <ui_main_window.h>

#include "home/page.hpp"
#include "market/page.hpp"

MainWindow::MainWindow(QWidget* parent)
    : UiWidget(parent)
{
    initUi();

    m_ui->titleBar->setContentContainer(m_ui->contentContainer);
    m_ui->titleBar->addPage<home::Page>("Home");
    m_ui->titleBar->addPage<market::Page>("Market");
}

MainWindow::~MainWindow() {}
