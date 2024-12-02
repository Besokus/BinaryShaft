
#pragma once
#include "../../button/button/button.h"

#include "../../scene/scene_manager/scene_manager.h" // 假设这是你的SceneManager类的头文件

extern bool running; // 外部声明的全局变量，用于控制游戏运行
extern SceneManager scene_manager; // 外部声明的SceneManager对象，用于场景切换

// 返回菜单按钮
class AchievementReturnMenuButton : public Button {
public:
    AchievementReturnMenuButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
        : Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
    ~AchievementReturnMenuButton() = default;

protected:
    void OnClick() override {
        scene_manager.SwitchTo(SceneManager::SceneType::Menu); // 切换到主菜单场景
    }
};

// 查看成就详细信息按钮（这里假设每个成就都有一个唯一的ID）
class AchievementDetailButton : public Button {
public:
    AchievementDetailButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height, int achievementId)
        : Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height), achievementId_(achievementId) {}
    ~AchievementDetailButton() = default;

protected:
    void OnClick() override 
    {
        // 这里可以添加查看成就详细信息的逻辑，比如打开一个对话框或切换到另一个界面显示详细信息
        // 假设我们有一个函数ShowAchievementDetail来显示详细信息
        //ShowAchievementDetail(achievementId_);
    }

private:
    int achievementId_; // 成就的ID，用于标识要查看的成就

    // 假设这是一个在其他地方定义的函数，用于显示成就的详细信息
    //void ShowAchievementDetail(int achievementId);
};


