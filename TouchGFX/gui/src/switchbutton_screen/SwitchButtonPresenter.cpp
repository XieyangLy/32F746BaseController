#include <gui/switchbutton_screen/SwitchButtonView.hpp>
#include <gui/switchbutton_screen/SwitchButtonPresenter.hpp>

SwitchButtonPresenter::SwitchButtonPresenter(SwitchButtonView& v)
    : view(v)
{
}

void SwitchButtonPresenter::activate()
{
	view.updatetext1String(model->getText1String());
	view.updatetext2String(model->getText2String());
}

void SwitchButtonPresenter::deactivate()
{

}

void SwitchButtonPresenter::notifyCurRadioSwitchChanged(int32_t index) 
{

}


void SwitchButtonPresenter::notifytext1StringChanged(std::string str) 
{
	view.updatetext1String(str);
}


void SwitchButtonPresenter::notifytext2StringChanged(std::string str) 
{
	view.updatetext2String(str);
}


void SwitchButtonPresenter::notifylightStatusChanged(int32_t index,bool status) 
{


}
