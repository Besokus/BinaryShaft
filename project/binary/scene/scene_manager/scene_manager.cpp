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

// 设置当前的场景
void SceneManager::SetCurrentScene(Scene* scene)
{
	// 设置当前的场景为scene
	current_scene = scene;
	// 并且进入当前的场景
	current_scene->OnEnter();
}

// 实现场景间的切换
void SceneManager::SwitchTo(SceneType type)
{
	// 退出旧场景
	current_scene->OnExit();
	// 选择新场景
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
	// 进入新场景
	current_scene->OnEnter();
}

// 更新场景的函数
void SceneManager::OnUpdate()
{
	current_scene->OnUpdate();
}

// 绘制场景的函数
void SceneManager::OnDraw()
{
	current_scene->OnDraw();
}

// 接受输入的函数
void SceneManager::OnInput(const ExMessage& msg)
{
	current_scene->OnInput(msg);
}
