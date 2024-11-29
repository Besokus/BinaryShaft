#pragma once
#include "../platform/platform.h"

extern IMAGE img_NULL_platform;

class WAPlatform :public Platform
{
public:
	WAPlatform(IMAGE img_platform) :Platform(img_platform) {}
	void PlatformChange()
	{
		if (is_visited)
		{
			img_platform = img_NULL_platform;
		}

	}
};