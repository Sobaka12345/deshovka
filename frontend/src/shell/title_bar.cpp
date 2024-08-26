#include "title_bar.hpp"

#include "content_container.hpp"
#include "title_bar_button.hpp"

#include <ui_title_bar.h>

#include <QButtonGroup>

namespace shell {

TitleBar::TitleBar(QWidget* parent)
    : UiWidget(parent)
    , m_container(nullptr)
{
    initUi();

    m_titleBarButtons = new QButtonGroup(this);
    connect(m_titleBarButtons, &QButtonGroup::buttonClicked, this, &TitleBar::onButtonClicked);
}

TitleBar::~TitleBar() {}

void TitleBar::setContentContainer(ContentContainer* container)
{
    m_container = container;
}

void TitleBar::addPage(const QString& title, std::function<QWidget*()> factoryFunc)
{
    TitleBarButton* btn = new TitleBarButton(this);
    layout()->addWidget(btn);
    m_titleBarButtons->addButton(btn);

    btn->setText(title);

    m_pageFactory.insert(btn, factoryFunc);
}

void TitleBar::onButtonClicked(QAbstractButton* button)
{
    Q_ASSERT(m_container);
    m_container->setContent(m_pageFactory.value(button, []() { return new QWidget; })());
}

}    //  namespace shell
