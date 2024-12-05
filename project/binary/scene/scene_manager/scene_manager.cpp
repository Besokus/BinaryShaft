#include "scene_manager.h"

extern Scene* game_scene;
extern Scene* menu_scene;
extern Scene* achievement_scene;
extern Scene* death_scene;
extern Scene* select_mode_scene;
extern Scene* pause_scene;
extern Scene* select_level_scene;
extern Scene* setup_scene;
extern Scene* showdetail_scene;
extern Scene* login_scene;
extern Scene* win_scene;
extern Scene* select_items_scene;
extern Scene* rank_scene;

// ���õ�ǰ�ĳ���
void SceneManager::SetCurrentScene(Scene* scene)
{
	// ���õ�ǰ�ĳ���Ϊscene
	current_scene = scene;
	// ���ҽ��뵱ǰ�ĳ���
	current_scene->OnEnter();
}

// ʵ�ֳ�������л�
void SceneManager::SwitchTo(SceneType type)
{
	// �˳��ɳ���
	current_scene->OnExit();
	// ѡ���³���
	switch (type)
	{
	case SceneType::Menu:
		current_scene = menu_scene;
		break;
	case SceneType::Game:
		current_scene = game_scene;
		break;
	case SceneType::SelectLevel:
		current_scene = select_level_scene;
		break;
	case SceneType::Pause:
		current_scene = pause_scene;
		break;
	case SceneType::SetUp:
		current_scene = setup_scene;
		break;
	case SceneType::SelectMode:
		current_scene = select_mode_scene;
		break;
	case SceneType::Death:
		current_scene = death_scene;
		break;
	case SceneType::Achievemnt:
		current_scene = achievement_scene;
		break;
	case SceneType::ShowDetail:
		current_scene = showdetail_scene;
		break;
	case SceneType::Login:
		current_scene = login_scene;
		break;
	case SceneType::Win:
		current_scene = win_scene;
		break;
	case SceneType::SelectItem:
		current_scene = select_items_scene;
		break;
	case SceneType::Rank:
		current_scene = rank_scene;
		break;
	default:
		break;
	}
	// �����³���
	current_scene->OnEnter();
}

// ���³����ĺ���
void SceneManager::OnUpdate()
{
	current_scene->OnUpdate();
}

// ���Ƴ����ĺ���
void SceneManager::OnDraw()
{
	current_scene->OnDraw();
}

// ��������ĺ���
void SceneManager::OnInput(const ExMessage& msg)
{
	current_scene->OnInput(msg);
}
