#include "death_scene.h"  
#include "../scene_manager/scene_manager.h"  
#include "../../player/player.h"  
#include "../../data.h"

extern SceneManager scene_manager;
extern IMAGE img_death_background;


extern int current_level;//���ֹؿ���



//�ڱ�����Ϸ������ͽ����а���£�current_score,current_level�����⵽���а������ĳ��ֲ���Ҫ����
void DeathScene::OnEnter()
{
}


void DeathScene::OnUpdate()
{


}


void DeathScene::OnDraw()
{
	putimage(0, 0, &img_death_background);
}

void DeathScene::OnInput(const ExMessage& msg)
{
	// ���̰���
	if (msg.message == WM_KEYUP)
	{
		// �л������˵�����
		if (level == 10)
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectItem);
		}
		else
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
		}
	}

	// ������
	if (msg.message == WM_LBUTTONDOWN)
	{
		// �л������˵�����
		if (level == 10)
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectItem);
		}
		else
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
		}
	}

}
