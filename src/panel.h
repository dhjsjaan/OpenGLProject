#ifndef PANEL_H_
#define PANEL_H_

#include "Head.h"
#include "../thirdparty/imgui-docking/imgui.h"
#include "string"
#include <functional>
#include "../thirdparty/imgui-docking/ImFileBrowser.h"
#include "scene.h"
#include "uiwidgets.h"
#include "../thirdparty/imgui-docking/imgui.h"

namespace LK
{

class Panel
{
public:
    Panel()
    {
        mCurrentFile = "< ... >";

        mFileDialog.SetTitle("Open mesh");
        mFileDialog.SetFileFilters({ ".fbx", ".obj" });
    }

    void render(Scene* mScene);

    void setMeshLoadCallback(const std::function<void(const std::string&)>& callback)
    {
        mMeshLoadCallback = callback;
    }

private:
    ImGui::FileBrowser mFileDialog;
    std::function<void(const std::string &)> mMeshLoadCallback;
    std::string mCurrentFile;
};

}

#endif
