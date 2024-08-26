#include "content_container.hpp"

#include <QVBoxLayout>

namespace shell {

ContentContainer::ContentContainer(QWidget* parent)
    : UiWidget(parent)
    , m_content(nullptr)
{
    setLayout(new QVBoxLayout);
    layout()->setSpacing(0);
    layout()->setContentsMargins(0, 0, 0, 0);
}

void ContentContainer::setContent(QWidget* content)
{
    if (m_content)
    {
        delete m_content;
    }

    content->setParent(this);
    layout()->addWidget(content);
    m_content = content;

    emit contentChanged();
}

}    //  namespace shell
