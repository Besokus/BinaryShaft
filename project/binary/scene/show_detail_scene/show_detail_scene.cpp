#include "show_detail_scene.h"

extern SceneManager scene_manager;

extern IMAGE img_detail_background;
extern IMAGE img_AC_detail;
extern IMAGE img_NULL_platform;
extern IMAGE img_AC_platform;
extern IMAGE img_WA_platform;
extern IMAGE img_CE_platform;
extern IMAGE img_SPEED_RIGHT_platform;
extern IMAGE img_SPEED_LEFT_platform;
extern IMAGE img_TLE_platform;
extern IMAGE img_MLE_platform;
extern IMAGE img_death_detail;
extern IMAGE img_ending_detail;
extern IMAGE img_detail_background;
extern IMAGE img_ending_detail;
extern IMAGE img_death_detail;
extern IMAGE image_item_carefully_BBQ;
extern IMAGE image_item_ctrl_Z;
extern IMAGE image_item_helpme_awei;
extern IMAGE image_item_hiraijin;
extern IMAGE image_item_once_again;
extern IMAGE image_item_the_world;

void ShowDetailScene::OnEnter() 
{
	page = 0;
}

void ShowDetailScene::OnDraw()
{
	putimage(0, 0, &img_detail_background);
	setbkmode(TRANSPARENT);

	settextstyle(25, 0, _T("IPix"));
	outtextxy(510, 200, _T("Esc����"));
	outtextxy(285, 430, _T("��"));
	outtextxy(375, 430, _T("ҳ"));

	if (is_A_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(100, 430, _T("A <- ��һҳ"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(100, 430, _T("A <- ��һҳ"));
	}

	if (is_D_down)
	{
		settextcolor(RGB(255, 255, 0));
		outtextxy(440, 430, _T("��һҳ - > D"));
		settextcolor(RGB(255, 255, 255));
	}
	else
	{
		outtextxy(440, 430, _T("��һҳ - > D"));
	}



	static TCHAR text[64];
	_stprintf_s(text, _T("%d"), page + 1);
	outtextxy(335, 430, text);

	switch (page)
	{
	case 0:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("������˵��:"));
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 235, _T("�����������˼��������޿��ܵ���Ϸ������ ����һȺ��Ĭ"));
		outtextxy(90, 265, _T("Ĭ���� �������ǵ��ǻۺ����鴴���� xcpcer-go-down ��"));
		outtextxy(90, 295, _T("�������Ŷ�: [��Ϸ��ѧ��]"));
		outtextxy(90, 325, _T("�����߳�Ա: ��ĳ  ����  Besokus  ��  Minato  ����"));
		outtextxy(210, 355, _T("yuuki  endl  ָ���ٳ�"));
		outtextxy(90, 390, _T("�¾������������Ϸ��������!"));
		outtextxy(370, 390, _T("�������¾�ÿһλ�Ȱ������"));
		break;
	case 1:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("��Ϸ����:"));
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 235, _T("����һλxcpcer������OJƽ̨�Ͻ�����������ˢ��ѵ�� ��"));
		outtextxy(90, 265, _T("ͻȻ�����ϵ磬������ǰһƬ��ڣ���������һ��ǿ�ҵ���׹"));
		outtextxy(90, 295, _T("�У�����Ҫ����������ȴ�о��Լ���������Ѿ���������..."));
		outtextxy(90, 325, _T("���ڣ����ٴθ��ܵ�����ߵĿռ䣬������ռ䲻���Ѳ���"));
		outtextxy(90, 355, _T("�ǹ�ȥ����Ϥ�Ŀռ䣬��������ֻ��0��1�Ŀռ䡪������뵽"));
		outtextxy(90, 385, _T("����д�ĳ����� ..."));

		break;
	case 2:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("��Ϸ����:"));
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 235, _T("���ڣ��㷢���Լ�������Ѫ��֮��������һ�������Ĵ��� ��"));
		outtextxy(90, 265, _T("�����ʶ�������Ϊһ�塣���ڣ���ֻ�ܲٿؼ����ϵ�A��D"));
		outtextxy(90, 295, _T("�����Լ��ƶ�����ʱע��ӽ����·���������ƽ̨����������"));
		outtextxy(90, 325, _T("������ܻ��������Ч����..."));
		outtextxy(90, 355, _T("���ֱ�������㣬����Ҫͨ�����е���Ŀ����(AC)��������"));
		outtextxy(90, 385, _T("����ʵ����.���򣬾���û���޾��Ĵ��뺣�� ��"));
		break;
	case 3:
		putimage(490, 245, &img_AC_platform);
		putimage(490, 290, &img_WA_platform);
		putimage(490, 335, &img_TLE_platform);
		putimage(490, 380, &img_MLE_platform);

		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("ƽ̨����͹���:"));
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 250, _T("AC: AC������1����Ŀ���ֽ���һ��!"));
		outtextxy(90, 295, _T("WA: AC������1����������뺣����!"));
		outtextxy(90, 340, _T("TLE: ��Ϸ�ٶȿ�ʼ�仯��ע������ȥ��"));
		outtextxy(90, 385, _T("MLE����ͼ�߽�仯���ɻ��Χ��С��!"));
		break;
	case 4:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("ƽ̨����͹���:"));
		putimage(490, 245, &img_CE_platform);
		putimage(490, 290, &img_NULL_platform);
		putimage(490, 335, &img_SPEED_LEFT_platform);
		putimage(490, 380, &img_SPEED_RIGHT_platform);
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 250, _T("CE��ֱ���˳���Ϸ������ʧ�ڴ���������!"));
		outtextxy(90, 295, _T("NULL�����·��������Ը��˰�!"));
		outtextxy(90, 340, _T("BOUNCE:���ϵ���ע��ͷ��Ҫ��������!"));
		outtextxy(90, 385, _T("SPEED_RIGHT: ����ƽ�⣬���Ҽ��ٿ�"));
		break;
	case 5:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("��������:"));
		putimage(510, 225, &image_item_carefully_BBQ);
		putimage(510, 325, &image_item_ctrl_Z);
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 250, _T("��ϸ�տ�:ƽ̨���ٶȽ���0.5������˼����"));
		outtextxy(90, 295, _T("һ����ô�ߣ�����ƽ̨ͻȻ�ӿ���!!!"));
		outtextxy(90, 340, _T("Ctrl_Z:ʱ����ݣ�ע��ʹ��ʱ��!�������"));
		outtextxy(90, 385, _T("�����벻���Ľ��..."));

		break;
	case 6:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("��������:"));
		putimage(510, 225, &image_item_helpme_awei);
		putimage(510, 325, &image_item_hiraijin);
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 250, _T("��ΰ����:��ΰ������ʹ���ڼ��������и���"));
		outtextxy(90, 295, _T("Ч����ƽ̨���ټӿ��ٶ�!"));
		outtextxy(90, 340, _T("������:˲��ת�Ƶ���ʾλ�ã�����ʱ��ʹ����"));
		outtextxy(90, 385, _T("��������֮���ã���������Ŀ�������0.01%.."));

		break;
	case 7:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("��������:"));
		putimage(510, 225, &image_item_once_again);
		putimage(510, 325, &image_item_the_world);
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 250, _T("�����:������ҵİ���!ʹ�ú󸴻���ң�����"));
		outtextxy(90, 295, _T("��һ����ʼλ�ã�ע��ֻ�ܴ���һ��!"));
		outtextxy(90, 340, _T("����³��:ʱͣ!��Ϸ��ͣ5�룬���ʱ�������"));
		outtextxy(90, 385, _T("����������ע��ƽ̨ͻȻ���ƶ���!"));

		break;

	case 8:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("��������:"));
		putimage(425, 230, &img_ending_detail);
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 320, _T("��ϲ��˳��ͨ�أ��ص�����ʵ����!"));
		break;
	case 9:
		settextstyle(25, 0, _T("IPix"));
		outtextxy(90, 200, _T("��������:"));
		putimage(425, 230, &img_death_detail);
		settextstyle(20, 0, _T("IPix"));
		outtextxy(90, 320, _T("���ź����㳹�׵���ʧ�ڴ���������!"));
		break;

	}
}

void ShowDetailScene::OnInput(const ExMessage& msg)
{
	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case 'A':
			page = (page - 1 + PAGE_SUM) % PAGE_SUM;
			is_A_down = true;
			break;
		case 'D':
			page = (page + 1) % PAGE_SUM;
			is_D_down = true;
			break;
		case VK_ESCAPE:
			scene_manager.SwitchTo(SceneManager::SceneType::Menu);
			break;
		}
	}
	if (msg.message == WM_KEYUP)
	{
		switch (msg.vkcode)
		{
		case 'A':
			is_A_down = false;
			break;
		case 'D':
			is_D_down = false;
			break;
		case VK_ESCAPE:
			scene_manager.SwitchTo(SceneManager::SceneType::Menu);
			break;
		}
	}

}

void ShowDetailScene::OnUpdate()
{

}

void ShowDetailScene::OnExit()
{


}