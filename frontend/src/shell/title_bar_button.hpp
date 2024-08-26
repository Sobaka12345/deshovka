#ifndef TITLE_BAR_BUTTON_HPP
#define TITLE_BAR_BUTTON_HPP

#include "ui_widget.hpp"

#include <QToolButton>

namespace Ui {
class TitleBarButton;
}

namespace shell {

class TitleBarButton : public UiWidget<QToolButton>
{
    Q_OBJECT

public:
    explicit TitleBarButton(QWidget* parent = nullptr);
    virtual ~TitleBarButton() override;
};

}

#endif    //  TITLE_BAR_BUTTON_HPP
