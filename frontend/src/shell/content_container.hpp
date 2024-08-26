#ifndef CONTENT_CONTAINER_HPP
#define CONTENT_CONTAINER_HPP

#include "ui_widget.hpp"

#include <QWidget>

namespace shell {

class ContentContainer : public UiWidget<QWidget>
{
    Q_OBJECT

    Q_PROPERTY(QWidget* content WRITE setContent NOTIFY contentChanged FINAL)

public:
    explicit ContentContainer(QWidget* parent = nullptr);

    void setContent(QWidget* content);

signals:
    void contentChanged();

private:
    QWidget* m_content;
};

}    //  namespace shell

#endif    //  CONTENT_CONTAINER_HPP
