#ifndef SWITCHBUTTON_VIEW_HPP
#define SWITCHBUTTON_VIEW_HPP

#include <gui_generated/switchbutton_screen/SwitchButtonViewBase.hpp>
#include <gui/switchbutton_screen/SwitchButtonPresenter.hpp>

class SwitchButtonView : public SwitchButtonViewBase
{
public:
    SwitchButtonView();
    virtual ~SwitchButtonView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SWITCHBUTTON_VIEW_HPP
