#ifndef HOME_PAGE_HPP
#define HOME_PAGE_HPP

#include "shell/ui_widget.hpp"

#include <QWidget>

namespace Ui {
class HomePage;
}

namespace home {

class Page : public shell::UiWidget<QWidget, Ui::HomePage>
{
    Q_OBJECT

public:
    explicit Page(QWidget* parent = nullptr);
    virtual ~Page() override;

signals:
};

}

#endif    //  HOME_PAGE_HPP
