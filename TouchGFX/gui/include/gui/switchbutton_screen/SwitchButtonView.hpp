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
		void updateCurRadioSwitch(int32_t index) ;
		void updatetext1String(std::string str);
		void updatetext2String(std::string str);
		void updatelightStatus(int32_t index,bool status);
protected:
};

#endif // SWITCHBUTTON_VIEW_HPP
