#ifndef SCPROCESS_VIEW_HPP
#define SCPROCESS_VIEW_HPP

#include <gui_generated/scprocess_screen/ScProcessViewBase.hpp>
#include <gui/scprocess_screen/ScProcessPresenter.hpp>

class ScProcessView : public ScProcessViewBase
{
public:
    ScProcessView();
    virtual ~ScProcessView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
protected:
    int processValue;
};

#endif // SCPROCESS_VIEW_HPP
