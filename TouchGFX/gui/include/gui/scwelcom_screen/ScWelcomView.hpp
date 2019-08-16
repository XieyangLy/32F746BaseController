#ifndef SCWELCOM_VIEW_HPP
#define SCWELCOM_VIEW_HPP

#include <gui_generated/scwelcom_screen/ScWelcomViewBase.hpp>
#include <gui/scwelcom_screen/ScWelcomPresenter.hpp>

class ScWelcomView : public ScWelcomViewBase
{
public:
    ScWelcomView();
    virtual ~ScWelcomView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCWELCOM_VIEW_HPP
