#ifndef SCPROCESS_PRESENTER_HPP
#define SCPROCESS_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScProcessView;

class ScProcessPresenter : public Presenter, public ModelListener
{
public:
    ScProcessPresenter(ScProcessView& v);

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

    virtual ~ScProcessPresenter() {};

private:
    ScProcessPresenter();

    ScProcessView& view;
};


#endif // SCPROCESS_PRESENTER_HPP
