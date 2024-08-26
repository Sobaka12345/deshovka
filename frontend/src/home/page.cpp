#include "page.hpp"

#include <ui_home_page.h>

namespace home {

Page::Page(QWidget* parent)
    : UiWidget(parent)
{
    initUi();
}

Page::~Page() {}

}
