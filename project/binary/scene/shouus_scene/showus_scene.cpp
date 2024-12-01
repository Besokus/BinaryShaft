#include "../../scene/shouus_scene/shouus_scene.h"
#include"../../button/showus_button/showus_button.h"

extern ShowUsButton* btn_showus_return;
extern IMAGE img_showus_background;


void ShowUsScene::OnEnter()
{
	btn_showus_return->OnEnter();

}

void ShowUsScene::OnUpdate()
{
}

void ShowUsScene::OnDraw()
{
	putimage(0, 0, &img_showus_background);

	btn_showus_return->OnDraw();

}


void ShowUsScene::OnInput(const ExMessage& msg)
{
	btn_showus_return->OnInput(msg);


}

void ShowUsScene::OnExit()
{

}
