#include "death_scene.h"  
#include "../scene_manager/scene_manager.h"  
#include "../../player/player.h"  
#include "../../data.h"

extern SceneManager scene_manager;
extern IMAGE img_death_background;

//Besokusд��
extern vector<Data> data_list;							// ������������,�����洢���е��������
extern Data* current_data;
extern int current_score;//������Ϸ��ҵ÷�
extern int current_level;//���ֹؿ���

extern Data* current_rank_data;
//int rank_num;//���а�����
extern vector<Data>rank_list[9];//ʮ����	
extern const int RANKPAGE;

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
			scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
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
		scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
		if (level == 10)
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
		}
		else
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
		}	}

}
