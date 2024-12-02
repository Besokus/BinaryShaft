
#include "achievement_scene.h"
#include "../scene_manager/scene_manager.h"
#include"../../button/achievement_button/achievement_button.h"
#include "../../button/button/button.h"
#include "../../data.h"
#include <vector>

extern SceneManager scene_manager;

extern AchievementReturnMenuButton* btn_achievement_rtmenu;
extern IMAGE img_achievement_background;

extern vector<Data> data_list;
extern Data* current_data;

void AchievementScene::OnEnter()
{
    // ��ʼ���ɾͽ��棬���ܰ������سɾ����ݻ����ý���״̬/
    btn_achievement_rtmenu->OnEnter();
    //btn_achievement_detail->OnEnter();
    current_data = &data_list[0];
    current_data->unlocked_achievement[1]=true;
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

    setbkmode(TRANSPARENT);

    settextstyle(30, 0, _T("IPix"));

    static TCHAR text[64];
    _stprintf_s(text, _T("��%dҳ"), current_page + 1);

    outtextxy(195, 520, text);

    if (is_A_down)
    {
        settextcolor(RGB(255, 255, 0));
        outtextxy(100, 520, _T("A"));
        outtextxy(150, 520, _T("<"));
        settextcolor(RGB(255, 255, 255));
    }
    else
    {
        outtextxy(100, 520, _T("A"));
        outtextxy(150, 520, _T("<"));
    }

    if (is_D_down)
    {
        settextcolor(RGB(255, 255, 0));
        outtextxy(340, 520, _T("D"));
        outtextxy(290, 520, _T(">"));
        settextcolor(RGB(255, 255, 255));
    }
    else
    {
        outtextxy(340, 520, _T("D"));
        outtextxy(290, 520, _T(">"));
    }

    if (current_data == nullptr)
    {
        settextstyle(50, 0, _T("IPix"));
        outtextxy(100, 350, _T("����ѡ��浵!!"));

        return;
    }

    if (!current_data->unlocked_achievement[current_page])
    {
        settextstyle(45, 0, _T("IPix"));
        outtextxy(50, 260, _T("???"));

        settextstyle(35, 0, _T("IPix"));
        outtextxy(50, 320, _T("?????"));
        
        return;
    }

    switch (current_page)
    {
    case 0:
        break;
    case 1:
        settextstyle(45, 0, _T("IPix"));
        outtextxy(50, 260, _T("���ǣ���"));

        settextstyle(35, 0, _T("IPix"));
        outtextxy(50, 320, _T("��������:����CE"));

        settextstyle(35, 0, _T("IPix"));
        outtextxy(50, 400, _T(""));
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    }

}


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
        case 'A':
            current_page = (current_page - 1 + PAGE_NUM) % PAGE_NUM;
            is_A_down = true;
            break;
        case 'D':
            current_page = (current_page + 1) % PAGE_NUM;
            is_D_down = true;
            break;
        }
    }
    if (msg.message == WM_KEYUP)
    {
        switch (msg.vkcode)
        {
        case 'A':
            is_A_down = false;
            break;
        case 'D':
            is_D_down = false;
            break;
        }
    }

}
