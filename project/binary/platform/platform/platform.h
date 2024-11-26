#pragma once

/*
	������:
	����:
		1.
		2.
	ʾ��:
		1.



*/
#include <graphics.h>
#include "../../player/player.h"

class Platform 
{
private:
	// int speed;
	// int length;
public:
	Platform() = default;
	~Platform() = default;


	virtual void OnUpdate() {}

	virtual void OnDraw() {}

	virtual void OnInput(const ExMessage& msg) {}

	bool CheckCollision(const Player& player);


};