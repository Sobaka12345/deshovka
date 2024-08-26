#ifndef UI_WIDGET_HPP
#define UI_WIDGET_HPP

#include <qnamespace.h>

class QWidget;

namespace shell {

template <typename ParentT, typename UiT = void>
class UiWidget : public ParentT
{
    static constexpr bool s_hasUiClass = !std::is_same_v<UiT, void>;

protected:
    explicit UiWidget(QWidget* parent = nullptr)
    {
        that()->setAttribute(Qt::WA_StyledBackground, that());
    }

    template <typename T = UiT>
    std::enable_if_t<s_hasUiClass, T*> initUi()
    {
        m_ui = new T;
        m_ui->setupUi(that());

        return m_ui;
    }

    ~UiWidget()
    {
        if constexpr (s_hasUiClass)
        {
            static_assert(std::is_default_constructible_v<UiT>);
            if (m_ui) delete m_ui;
        }
    }

protected:
    UiT* m_ui = nullptr;

private:
    ParentT* that() { return static_cast<ParentT*>(this); }
};

}    //  namespace shell

#endif    //  UI_WIDGET_HPP
