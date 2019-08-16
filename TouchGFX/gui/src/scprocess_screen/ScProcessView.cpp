#include <gui/scprocess_screen/ScProcessView.hpp>

ScProcessView::ScProcessView()
{
  processValue = 0;
}

void ScProcessView::setupScreen()
{
    ScProcessViewBase::setupScreen();
    circleProgress1.setValue(0);
}

void ScProcessView::tearDownScreen()
{
    ScProcessViewBase::tearDownScreen();
}

void ScProcessView::handleTickEvent()
{
  if(processValue++ > 100)
  {
    processValue = 0;
  }
  circleProgress1.setValue(processValue);
}
