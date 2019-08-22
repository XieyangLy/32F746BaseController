#ifndef FILEMANAGER_VIEW_HPP
#define FILEMANAGER_VIEW_HPP

#include <gui_generated/filemanager_screen/FileManagerViewBase.hpp>
#include <gui/filemanager_screen/FileManagerPresenter.hpp>

class FileManagerView : public FileManagerViewBase
{
public:
    FileManagerView();
    virtual ~FileManagerView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // FILEMANAGER_VIEW_HPP
