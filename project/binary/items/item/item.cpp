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
		if (time_keeper == duration)
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
		if (time_keeper == cd)
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
			if(!istriggered&&!is_cding)
				this->triggering();
			break;
		}
	}
}