#pragma once
#include "../../player/player.h"
#include "../../scene/game_scene/game_scene.h"
#include"../../map/map.h"

class Map_Msg;
class Player;

class item
{
protected:
	int id;//����id
	int time_keeper;//��ʱ��
	int cd;//����cd
	int duration;//���߳���ʱ��
	bool is_cding;//�Ƿ���cd��
	bool istriggered;//�Ƿ�ʹ��
	Player* player;
	Map_Msg* map_msg;
public:
	item() = default;
	~item() = default;

	void OnInput(const ExMessage& msg);

	virtual void OnUpdate();

	virtual void OnDarw() = 0;

	virtual void triggering() = 0;

	virtual void end_trigger() = 0;
};
