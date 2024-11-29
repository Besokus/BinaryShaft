#include "death_scene.h"  
#include "../scene_manager/scene_manager.h"  
#include "../../player/player.h"  

extern SceneManager scene_manager;

void DeathScene::OnEnter() 
{
    // 可以在这里初始化死亡界面的特定 资源或状态
    // 比如显示玩家的死亡信息、分数等
}

void DeathScene::OnUpdate() 
{
    // 更新逻辑，比如倒计时到重启或主菜单
    // 这里可以有一个简单的计时器，当长时间没有下一步操作时，直接跳到主菜单
    // 感觉也可以不要

}

int DeathScene::GetPlayerScore() 
{
    //接收玩家分数
    return 1;
}

void DeathScene::OnDraw() 
{
    // 绘制死亡界面的内容
    // 使用特定的绘图API或框架函数来显示“游戏结束”、“你的分数”等信息
    // 例如，使用outtextxy（如果可用）或其他绘图函数
    outtextxy(10, 10, _T("GAME OVER"));
    // 有一个函数来获取玩家的分数
    int score = GetPlayerScore();
    static TCHAR text[64];
    _stprintf_s(text, _T("本次获得分数:%d"), score);  //显示分数
    outtextxy(10, 30, text);
    outtextxy(10, 50, _T("按任意键返回主菜单"));
}

void DeathScene::OnInput(const ExMessage& msg) 
{
    // 处理输入，比如检测按键来切换到主菜单或其他场景
    if (msg.message == WM_KEYDOWN || msg.message == WM_SYSKEYDOWN) {
        // 切换到主菜单场景
        scene_manager.SwitchTo(SceneManager::SceneType::Menu);
    }

}
