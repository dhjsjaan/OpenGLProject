#ifndef UIWIDGETS_H_
#define UIWIDGETS_H_

#include "../thirdparty/imgui-docking/imgui.h"
#include "../thirdparty/imgui-docking/imgui_internal.h"

namespace LK
{

static void draw_vec3_widget(const std::string& label, glm::vec3& values, float columnWidth = 100.0f)//构建用户界面组件
{
    ImGuiIO& io = ImGui::GetIO();//字体
    auto boldFont = io.Fonts->Fonts[0];


    ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());//列宽，项间距
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });

    float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;//按钮，行高
    ImVec2 buttonSize = { lineHeight + 3.0f, lineHeight };

    ImGui::PushFont(boldFont);//按钮控制
    ImGui::Button("X", buttonSize);
    ImGui::PopFont();

    ImGui::SameLine();//滑块控制
    ImGui::DragFloat("##X", &values.x, 0.1f, 0.0f, 0.0f, "%.2f");
    ImGui::PopItemWidth();
    ImGui::SameLine();

    ImGui::PushFont(boldFont);
    ImGui::Button("Y", buttonSize);
    ImGui::PopFont();

    ImGui::SameLine();
    ImGui::DragFloat("##Y", &values.y, 0.1f, 0.0f, 0.0f, "%.2f");
    ImGui::PopItemWidth();
    ImGui::SameLine();

    ImGui::PushFont(boldFont);
    ImGui::Button("Z", buttonSize);
    ImGui::PopFont();

    ImGui::SameLine();
    ImGui::DragFloat("##Z", &values.z, 0.1f, 0.0f, 0.0f, "%.2f");
    ImGui::PopItemWidth();

    ImGui::PopStyleVar();


}

}

#endif
