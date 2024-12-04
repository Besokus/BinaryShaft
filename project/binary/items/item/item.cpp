#include"item.h"

/*
	�����ˣ���ĳ
	���ܣ�
		1.���istriggeredΪtrue ���¼�ʱ��time_keeper
		2.���time_keeper==duration ���޸�istriggeredΪfause��������end
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

// ���ƴ���͸���ȵĺ�ɫ�ɰ溯��
void item::DrawBlackOverlay(int x, int y, int width, int height, float overlay_ratio) {

	// �趨�ɰ����ɫ��ͨ�������Ҷ�ֵ��ģ��͸����
	COLORREF overlayColor = RGB(0, 0, 0); // ��ʼΪ����ɫ
	if (overlay_ratio < 1.0f) {
		// ͨ��overlay_ratio�����Ҷ�ֵ��ģ��͸����Ч��
		// ʹ��overlay_ratio����255���õ�һ���Ҷ�ֵ��0-255��
		BYTE grayValue = static_cast<BYTE>(overlay_ratio * 255);
		overlayColor = RGB(grayValue, grayValue, grayValue);
	}

	// ���ƾ����ɰ�
	setfillcolor(overlayColor); // ���������ɫ
	bar(x, y, x + width, y + height); // ���ƾ���
}
// ʾ������
// ������(50, 50)λ�û���һ��100x100��С�ľ����ɰ棬͸����Ϊ50%��overlay_ratio=0.5��
// DrawBlackOverlay(50, 50, 100, 100, 0.5f);