#include "scene_manager.h"

extern Scene* game_scene;
extern Scene* menu_scene;
extern Scene* achievement_scene;
extern Scene* death_scene;
extern Scene* select_mode_scene;
extern Scene* pause_scene;
extern Scene* select_level_scene;
extern SetUpScene* setup_scene;

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
	if (current_scene == pause_scene && type == SceneType::Game)
	{
		current_scene = game_scene;
		return;
	}

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
