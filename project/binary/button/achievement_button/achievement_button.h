
#pragma once
#include "../../button/button/button.h"

#include "../../scene/scene_manager/scene_manager.h" // �����������SceneManager���ͷ�ļ�

extern bool running; // �ⲿ������ȫ�ֱ��������ڿ�����Ϸ����
extern SceneManager scene_manager; // �ⲿ������SceneManager�������ڳ����л�

// ���ز˵���ť
class AchievementReturnMenuButton : public Button {
public:
    AchievementReturnMenuButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height)
        : Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height) {}
    ~AchievementReturnMenuButton() = default;

protected:
    void OnClick() override {
        scene_manager.SwitchTo(SceneManager::SceneType::Menu); // �л������˵�����
    }
};

// �鿴�ɾ���ϸ��Ϣ��ť���������ÿ���ɾͶ���һ��Ψһ��ID��
class AchievementDetailButton : public Button {
public:
    AchievementDetailButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed, int width, int height, int achievementId)
        : Button(rect, path_img_idle, path_img_hovered, path_img_pushed, width, height), achievementId_(achievementId) {}
    ~AchievementDetailButton() = default;

protected:
    void OnClick() override 
    {
        // ���������Ӳ鿴�ɾ���ϸ��Ϣ���߼��������һ���Ի�����л�����һ��������ʾ��ϸ��Ϣ
        // ����������һ������ShowAchievementDetail����ʾ��ϸ��Ϣ
        //ShowAchievementDetail(achievementId_);
    }

private:
    int achievementId_; // �ɾ͵�ID�����ڱ�ʶҪ�鿴�ĳɾ�

    // ��������һ���������ط�����ĺ�����������ʾ�ɾ͵���ϸ��Ϣ
    //void ShowAchievementDetail(int achievementId);
};


