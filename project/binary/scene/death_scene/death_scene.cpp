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
extern void WriteData();
extern void WriteRankData();
extern Data* current_rank_data;
//int rank_num;//���а�����
extern vector<Data>rank_list[9];//ʮ����	
extern const int RANKPAGE;

//�ڱ�����Ϸ������ͽ����а���£�current_score,current_level�����⵽���а������ĳ��ֲ���Ҫ���鷳

void DeathScene::OnEnter()
{
	mciSendString(_T("play resources/����.mp3 from 0"), NULL, 0, NULL);
	mciSendString(_T("stop bgm_normal_1"), NULL, 0, NULL);
	static TCHAR text[64];
	_stprintf_s(text, _T("���յ÷�:%d !"), 114514);

	MessageBox(GetHWnd(), text, _T("Game Over"), MB_OK);
}

/*
* 
* Besokusд��
void DeathScene::OnEnter()
{
	static TCHAR text[64];
	_stprintf_s(text, _T("���յ÷�:%d !"), 114514);
	//����Ϸ�����󽫱��ֵ÷ּ������Ҹùؿ��������£�ѡ��ߵĵ÷ּ��룩
	//�����ұ�����Ϸ����
	current_score = GetPlayerScore();
	//��ǰ�÷ִ��ڵ�ʱ���ٽ��÷�д��������
	if (current_score > current_data->level_score[current_level]) {
		//������ҷ���
		for (int i = 0; i < data_list.size(); i++) {
			if ((strcmp(data_list[i].name, current_data->name))==0) {
				data_list[i].level_score[current_level] = current_score;
				break;
			}
		}
		//�����а��Ӧ��Ϣ����
		for (int i = 0; i < data_list.size(); i++) {
			if ((strcmp(rank_list[current_level][i].name, current_data->name)) == 0) {
				rank_list[current_level][i].level_score[current_level] = current_score;
				break;
			}
		}

	}

	MessageBox(GetHWnd(), text, _T("Game Over"), MB_OK);
}
*/

void DeathScene::OnUpdate()
{


}

int DeathScene::GetPlayerScore()
{
	//������ҷ���
	return 1;
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
		if (level == 10)
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectMode);
		}
		else
		{
			scene_manager.SwitchTo(SceneManager::SceneType::SelectLevel);
		}
	}

}
