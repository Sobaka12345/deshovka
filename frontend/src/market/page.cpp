#include "page.hpp"

#include <ui_market_page.h>

namespace market {

Page::Page(QWidget* parent)
    : UiWidget(parent)
{
    initUi();
}

Page::~Page() {}

}
