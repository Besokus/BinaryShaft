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