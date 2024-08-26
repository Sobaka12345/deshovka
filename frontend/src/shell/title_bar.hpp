#ifndef TITLE_BAR_Hpp
#define TITLE_BAR_Hpp

#include "ui_widget.hpp"

#include <QWidget>

class QAbstractButton;
class QButtonGroup;

namespace Ui {
class TitleBar;
}

namespace shell {

class ContentContainer;

class TitleBar : public UiWidget<QWidget, Ui::TitleBar>
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget* parent = nullptr);
    virtual ~TitleBar() override;

    void setContentContainer(ContentContainer* container);

    template <typename PageT>
    void addPage(const QString& title)
    {
        addPage(title, []() { return new PageT; });
    }

    void addPage(const QString& title, std::function<QWidget*()> factoryFunc);

private slots:
    void onButtonClicked(QAbstractButton* button);

private:
    QButtonGroup* m_titleBarButtons;
    ContentContainer* m_container;
    QMap<QAbstractButton*, std::function<QWidget*()>> m_pageFactory;
};

}    //  namespace shell

#endif    //  TITLE_BAR_HPP
