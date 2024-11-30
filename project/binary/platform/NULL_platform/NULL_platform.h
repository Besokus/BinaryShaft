#pragma once
#include "../platform/platform.h"

class NULLPlatform :public Platform
{
public:
	NULLPlatform(IMAGE img_platform) :Platform(img_platform) {}
	void PlatformChange(Player* player)
	{

	}
};