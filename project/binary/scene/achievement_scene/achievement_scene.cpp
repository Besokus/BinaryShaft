//#include "achievement_scene.h"
//#include "../scene_manager/scene_manager.h"
//#include "../../achievement/achievement.h"
//#include <vector>
//#include<windows.h>
//
//
//extern SceneManager scene_manager;
//extern std::vector<Achievement*> achievement_list; // �������Ǵ洢���гɾ͵�ȫ�ֱ���
//
//void AchieveScene::OnEnter() 
//{
//    // ��ʼ���ɾͽ��棬���ܰ������سɾ����ݻ����ý���״̬
//}
//
//void AchieveScene::OnUpdate() 
//{
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
//}
//
//void AchieveScene::OnDraw() {
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
//    outtextxy(10, y_offset + 20, _T("��ESC�������˵�"));
//}
//
//void AchieveScene::OnInput(const ExMessage& msg) {
//    // �����û����룬���簴���¼�
//    if (msg.message == WM_KEYDOWN) 
//    {
//        switch (msg.vkcode) 
//        {
//        case VK_ESCAPE:
//            scene_manager.SwitchTo(SceneManager::SceneType::Menu);
//            break;
//            // ��������������������߼�������鿴�ɾ������
//        }
//    }
//}
