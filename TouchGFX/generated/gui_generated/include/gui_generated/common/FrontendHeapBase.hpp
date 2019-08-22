/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDHEAPBASE_HPP
#define FRONTENDHEAPBASE_HPP

#include <common/Meta.hpp>
#include <common/Partition.hpp>
#include <mvp/MVPHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <touchgfx/transitions/CoverTransition.hpp>

#include <touchgfx/transitions/SlideTransition.hpp>


#include <gui/common/FrontendApplication.hpp>
#include <gui/model/Model.hpp>

#include <gui/scwelcom_screen/ScWelcomView.hpp>
#include <gui/scwelcom_screen/ScWelcomPresenter.hpp>
#include <gui/scprocess_screen/ScProcessView.hpp>
#include <gui/scprocess_screen/ScProcessPresenter.hpp>
#include <gui/switchbutton_screen/SwitchButtonView.hpp>
#include <gui/switchbutton_screen/SwitchButtonPresenter.hpp>
#include <gui/filemanager_screen/FileManagerView.hpp>
#include <gui/filemanager_screen/FileManagerPresenter.hpp>


/**
 * This class provides the memory that shall be used for memory allocations
 * in the frontend. A single instance of the FrontendHeap is allocated once (in heap
 * memory), and all other frontend objects such as views, presenters and data model are
 * allocated within the scope of this FrontendHeap. As such, the RAM usage of the entire
 * user interface is sizeof(FrontendHeap).
 *
 * @note The FrontendHeap reserves memory for the most memory-consuming presenter and
 * view only. The largest of these classes are determined at compile-time using template
 * magic. As such, it is important to add all presenters, views and transitions to the
 * type lists in this class.
 *
 */
class FrontendHeapBase : public MVPHeap
{
public:
    /**
     * A list of all view types. Must end with meta::Nil.
     * @note All view types used in the application MUST be added to this list!
     */
    typedef meta::TypeList< ScWelcomView,
            meta::TypeList< ScProcessView,
            meta::TypeList< SwitchButtonView,
            meta::TypeList< FileManagerView,
            meta::Nil > > >
            > GeneratedViewTypes;

    /**
     * Determine (compile time) the View type of largest size.
     */
    typedef meta::select_type_maxsize< GeneratedViewTypes >::type MaxGeneratedViewType;

    /**
     * A list of all presenter types. Must end with meta::Nil.
     * @note All presenter types used in the application MUST be added to this list!
     */
    typedef meta::TypeList< ScWelcomPresenter,
            meta::TypeList< ScProcessPresenter,
            meta::TypeList< SwitchButtonPresenter,
            meta::TypeList< FileManagerPresenter,
            meta::Nil > > >
            > GeneratedPresenterTypes;

    /**
     * Determine (compile time) the Presenter type of largest size.
     */
    typedef meta::select_type_maxsize< GeneratedPresenterTypes >::type MaxGeneratedPresenterType;

    /**
     * A list of all transition types. Must end with meta::Nil.
     * @note All transition types used in the application MUST be added to this list!
     */
    typedef meta::TypeList< NoTransition,
            meta::TypeList< CoverTransition<EAST>,
            meta::TypeList< SlideTransition<EAST>,
            meta::Nil > >
            > GeneratedTransitionTypes;

    /**
     * Determine (compile time) the Transition type of largest size.
     */
    typedef meta::select_type_maxsize< GeneratedTransitionTypes >::type MaxGeneratedTransitionType;

    virtual void gotoStartScreen(FrontendApplication& app)
    {
        app.gotoScWelcomScreenNoTransition();
    }
protected:
    FrontendHeapBase(AbstractPartition& presenters, AbstractPartition& views, AbstractPartition& transitions, FrontendApplication& app)
        : MVPHeap(presenters, views, transitions, app)
    {

    }

};

#endif // FRONTENDHEAPBASE_HPP
