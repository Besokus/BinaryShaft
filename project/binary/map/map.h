#pragma once
#include "../../player/player.h"
#include "../../scene/game_scene/game_scene.h"
extern int level;
struct Map_massage
{
	float speed;
	int target_score;
	std::vector<int> platform_weight;
	std::vector<bool> item_choice;
};
extern Map_massage map_massage[11];

class Map_Msg
{
public:
	int level;
	//int length;
	//int width;
	float speed;
	int score;
	int target_score;
	std::vector<int> platform_weight;
	std::vector<bool> item_choice;
	Map_Msg(int level) 
	{
		score = 0;
		speed = map_massage[level].speed;
		this->level = level;
		target_score = map_massage[level].target_score;
		platform_weight.insert(platform_weight.begin(), map_massage[level].platform_weight.begin(), map_massage[level].platform_weight.end());
		item_choice.insert(item_choice.begin(), map_massage[level].item_choice.begin(), map_massage[level].item_choice.end());
	}
	~Map_Msg() {}
};