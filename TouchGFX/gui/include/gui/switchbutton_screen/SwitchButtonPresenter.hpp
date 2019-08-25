#ifndef SWITCHBUTTON_PRESENTER_HPP
#define SWITCHBUTTON_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SwitchButtonView;

class SwitchButtonPresenter : public Presenter, public ModelListener
{
public:
    SwitchButtonPresenter(SwitchButtonView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~SwitchButtonPresenter() {};

		virtual void notifyCurRadioSwitchChanged(int32_t index);
		virtual void notifytext1StringChanged(std::string str);
		virtual void notifytext2StringChanged(std::string str);
		virtual void notifylightStatusChanged(int32_t index,bool status);	
			
			
private:
    SwitchButtonPresenter();

    SwitchButtonView& view;
};


#endif // SWITCHBUTTON_PRESENTER_HPP
