/*
	������:ja1u0va
	����:
		1.����ȫ�ֱ���





*/
#include "../scene/scene_manager/scene_manager.h"
#include "../scene/scene/scene.h"
#include "../player/player.h"
#include "../platform/platform/platform.h"
#include <vector>


// ����ͼƬ����
// example:
// IMAGE img_menu_background;
// img_(class)_(xxx)_(status)_(direction)


// ����ͼ������
// example:
// Atlas atlas_peashooter_idle_left;
// atlas_(class)_(status)_(direction)




bool running = true;

int level = 0;


Scene* menu_scene = nullptr;
Scene* game_scene = nullptr;
Scene* select_Level_scene = nullptr;
Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;
//Scene* pause_scene = nullptr;

SceneManager scene_manager;

Player* player = nullptr;
std::vector<Platform*> platform_list;
