#include"item.h"

/*
	负责人：余某
	功能：
		1.如果istriggered为true 更新计时器time_keeper
		2.如果time_keeper==duration ，修改istriggered为fause，并调用end
*/
void item::OnUpdate()
{
	if (istriggered)
	{
		time_keeper++;
		during_change();
		if (time_keeper >= duration)
		{
			istriggered = false;
			is_cding = true;
			this->end_trigger();
			time_keeper = 0;
		}
	}
	else if (is_cding)
	{
		time_keeper++;
		if (time_keeper >= cd)
		{
			is_cding = false;
			time_keeper = 0;
		}
	}
}

void item::OnInput(const ExMessage& msg)
{
	if (msg.message == WM_KEYDOWN)
	{
		switch (msg.vkcode)
		{
		case 'q':
		case 'Q':
		case 'e':
		case 'E':
			if (this->id != 5)
			{
				if (!istriggered && !is_cding)
					this->triggering();
			}
			break;
		}
	}
}

// 绘制带有透明度的黑色蒙版函数
void item::DrawBlackOverlay(int x, int y, int width, int height, float overlay_ratio) {

	// 设定蒙版的颜色，通过调整灰度值来模拟透明度
	COLORREF overlayColor = RGB(0, 0, 0); // 初始为纯黑色
	if (overlay_ratio < 1.0f) {
		// 通过overlay_ratio调整灰度值，模拟透明度效果
		// 使用overlay_ratio乘以255来得到一个灰度值（0-255）
		BYTE grayValue = static_cast<BYTE>(overlay_ratio * 255);
		overlayColor = RGB(grayValue, grayValue, grayValue);
	}

	// 绘制矩形蒙版
	setfillcolor(overlayColor); // 设置填充颜色
	bar(x, y, x + width, y + height); // 绘制矩形
}
// 示例调用
// 假设在(50, 50)位置绘制一个100x100大小的矩形蒙版，透明度为50%（overlay_ratio=0.5）
// DrawBlackOverlay(50, 50, 100, 100, 0.5f);