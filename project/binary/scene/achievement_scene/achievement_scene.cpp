//#include "achievement_scene.h"
//#include "../scene_manager/scene_manager.h"
//#include "../../achievement/achievement.h"
//#include <vector>
//#include<windows.h>
//
//
//extern SceneManager scene_manager;
//extern std::vector<Achievement*> achievement_list; // 假设这是存储所有成就的全局变量
//
//void AchieveScene::OnEnter() 
//{
//    // 初始化成就界面，可能包括加载成就数据或重置界面状态
//}
//
//void AchieveScene::OnUpdate() 
//{
//    // 这里我们简单遍历成就列表，检查每个成就的状态是否已更改(是否有新解锁啥的)
//    for (Achievement* achievement : achievement_list) 
//    {
//        if (achievement->IsNewlyUnlocked()) 
//        {
//            // 如果成就新解锁，可以执行一些操作，比如显示提示信息或更新界面,比如提示解锁了新道具
//            achievement->MarkAsViewed(); // 标记为已查看，避免重复提示
//            // 这里可以添加代码来更新界面或显示通知
//        }
//
//    }
//}
//
//void AchieveScene::OnDraw() {
//    // 绘制成就界面，展示已解锁的成就
//    static TCHAR text[256];
//    int y_offset = 10; // 初始的y坐标偏移量
//
//    for (Achievement* achievement : achievement_list) {
//        if (achievement->IsUnlocked()) {
//            // 使用_stprintf_s或其他字符串格式化函数来设置文本
//            _stprintf_s(text, _T("成就: %s\n"), achievement->GetName().c_str());
//
//            // DrawMultilineText(10, y_offset, text); //可能存在多行输出情况，不太清楚这个函数存在的必要大不大
//
//            outtextxy(10, y_offset, text);
//            y_offset += 20; // 增加y坐标偏移量以绘制下一个成就
//
//            // 如果需要，还可以添加其他信息，如成就描述或解锁日期
//        }
//    }
//
//    // 可以在界面底部添加一些提示信息或导航按钮
//    outtextxy(10, y_offset + 20, _T("按ESC返回主菜单"));
//}
//
//void AchieveScene::OnInput(const ExMessage& msg) {
//    // 处理用户输入，比如按键事件
//    if (msg.message == WM_KEYDOWN) 
//    {
//        switch (msg.vkcode) 
//        {
//        case VK_ESCAPE:
//            scene_manager.SwitchTo(SceneManager::SceneType::Menu);
//            break;
//            // 可以添加其他按键处理逻辑，比如查看成就详情等
//        }
//    }
//}
