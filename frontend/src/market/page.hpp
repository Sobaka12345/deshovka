#ifndef MARKET_PAGE_HPP
#define MARKET_PAGE_HPP

#include "shell/ui_widget.hpp"

#include <QWidget>

namespace Ui {
class MarketPage;
}

namespace market {

class Page : public shell::UiWidget<QWidget, Ui::MarketPage>
{
    Q_OBJECT

public:
    explicit Page(QWidget* parent = nullptr);
    virtual ~Page() override;

signals:
};

}

#endif    //  MARKET_PAGE_HPP
