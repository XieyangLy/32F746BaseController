#ifndef SCWELCOM_PRESENTER_HPP
#define SCWELCOM_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScWelcomView;

class ScWelcomPresenter : public Presenter, public ModelListener
{
public:
    ScWelcomPresenter(ScWelcomView& v);

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

    virtual ~ScWelcomPresenter() {};

private:
    ScWelcomPresenter();

    ScWelcomView& view;
};


#endif // SCWELCOM_PRESENTER_HPP
