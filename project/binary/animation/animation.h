#pragma once

/*
	负责人:ja1u0va
	功能:
		1.
		2.
	示例:
		1.



*/

#include <graphics.h>
#include <functional>
#include "../atlas/atlas.h"

class Animation
{

private:
	int timer = 0;					// 计时器
	int interval = 0;				// 帧间隔
	int idx_frame = 0;				// 帧索引
	bool is_loop = true;			// 是否循环
	Atlas* atlas = nullptr;			// 此动画使用的图集
	std::function<void()> callback;	// function是一个模板类


public:
	Animation() = default;
	~Animation() = default;

	// 重置动画状态
	// 当动画需要从头播放时使用
	void Reset();

	// 设置动画所使用的图集
	void SetAtlas(Atlas* new_atlas);

	// 设置是否循环播放动画
	void SetLoop(bool flag);

	// 设置帧数间隔
	void SetInterval(int ms);

	// 获取当前帧索引
	int GetIdxFrame();

	// 获取当前帧图片
	IMAGE* GetFrame();

	// 检查动画是否播放结束
	bool CheckFinished();

	// 动画更新方法
	void OnUpDate(int delta);

	// 动画绘制方法
	void OnDraw(int x, int y)const;

	void SetCallBack(std::function<void()> callback);
};