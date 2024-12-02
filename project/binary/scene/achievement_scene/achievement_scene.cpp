
#include "achievement_scene.h"
#include "../scene_manager/scene_manager.h"
#include"../../button/achievement_button/achievement_button.h"
#include "../../achievement/achievement.h"
#include "../../button/button/button.h"
#include <vector>
extern bool running;
extern SceneManager scene_manager;

extern std::vector<Achievement*> achievement_list; // �������Ǵ洢���гɾ͵�ȫ�ֱ���
extern AchievementReturnMenuButton* btn_achievement_rtmenu;
extern AchievementDetailButton* btn_achievement_detail;
extern IMAGE img_achievement_background;


void AchievementScene::OnEnter()
{
    // ��ʼ���ɾͽ��棬���ܰ������سɾ����ݻ����ý���״̬/
    btn_achievement_rtmenu->OnEnter();
    //btn_achievement_detail->OnEnter();
}
//
void AchievementScene::OnUpdate()
{
    //    // �������Ǽ򵥱����ɾ��б����ÿ���ɾ͵�״̬�Ƿ��Ѹ���(�Ƿ����½���ɶ��)
    //    for (Achievement* achievement : achievement_list) 
    //    {
    //        if (achievement->IsNewlyUnlocked()) 
    //        {
    //            // ����ɾ��½���������ִ��һЩ������������ʾ��ʾ��Ϣ����½���,������ʾ�������µ���
    //            achievement->MarkAsViewed(); // ���Ϊ�Ѳ鿴�������ظ���ʾ
    //            // ���������Ӵ��������½������ʾ֪ͨ
    //        }
    //
    //    }
}

void AchievementScene::OnDraw() {
    putimage(0, 0, &img_achievement_background);
    
    btn_achievement_rtmenu->OnDraw();
    //btn_achievement_detail->OnDraw();

    //    // ���Ƴɾͽ��棬չʾ�ѽ����ĳɾ�
    //    static TCHAR text[256];
    //    int y_offset = 10; // ��ʼ��y����ƫ����
    //
    //    for (Achievement* achievement : achievement_list) {
    //        if (achievement->IsUnlocked()) {
    //            // ʹ��_stprintf_s�������ַ�����ʽ�������������ı�
    //            _stprintf_s(text, _T("�ɾ�: %s\n"), achievement->GetName().c_str());
    //
    //            // DrawMultilineText(10, y_offset, text); //���ܴ��ڶ�������������̫�������������ڵı�Ҫ�󲻴�
    //
    //            outtextxy(10, y_offset, text);
    //            y_offset += 20; // ����y����ƫ�����Ի�����һ���ɾ�
    //
    //            // �����Ҫ�����������������Ϣ����ɾ��������������
    //        }
    //    }
    //
    //    // �����ڽ���ײ����һЩ��ʾ��Ϣ�򵼺���ť
    // outtextxy(10, y_offset + 20, _T("��ESC�������˵�"));
}
//
void AchievementScene::OnInput(const ExMessage& msg) {
    btn_achievement_rtmenu->OnInput(msg);
    
    //btn_achievement_detail->OnInput(msg);
    
    // �����û����룬���簴���¼�
    if (msg.message == WM_KEYDOWN)
    {
        switch (msg.vkcode)
        {
        case VK_ESCAPE:
            scene_manager.SwitchTo(SceneManager::SceneType::Menu);
            break;
            // ��������������������߼�������鿴�ɾ������
        }
    }
}
