#pragma once
#include "../platform/platform.h"

extern IMAGE img_NULL_platform;

class ACPlatform :public Platform
{
public:
	ACPlatform(IMAGE img_platform) :Platform(img_platform) {}
	void PlatformChange()
	{
		if (is_visited) 
		{
			img_platform = img_NULL_platform;
		}

	}
};