#include "animation.h"

extern void PutImage(int x, int y, IMAGE* img);

// 重置动画状态
// 当动画需要从头播放时使用
void Animation::Reset()
{
	timer = 0;
	idx_frame = 0;
}

// 设置动画所使用的图集
void Animation::SetAtlas(Atlas* new_atlas)
{
	// 为了避免重复设置产生的帧索引越界
	// 调用Reset重置动画
	Reset();
	atlas = new_atlas;
}

// 设置是否循环播放动画
void Animation::SetLoop(bool flag)
{
	is_loop = flag;
}

// 设置帧数间隔
void Animation::SetInterval(int ms)
{
	interval = ms;
}

// 获取当前帧索引
int Animation::GetIdxFrame()
{
	return idx_frame;
}

// 获取当前帧图片
IMAGE* Animation::GetFrame()
{
	return atlas->GetImage(idx_frame);
}

// 检查动画是否播放结束
bool Animation::CheckFinished()
{
	// 当动画被设置为循环播放时,则永远不会播放结束
	if (is_loop) return false;

	// 反之,检查当前帧索引是否到达图集的尾部
	return (idx_frame == atlas->GetSize() - 1);
}

// 动画更新方法
void Animation::OnUpDate(int delta)
{
	// 每次更新时检查定时器的值
	timer += delta;
	// 检查定时器的值是否到达帧间隔
	if (timer >= interval)
	{
		// 如果到达帧间隔
		// 重置计时器,并累加帧索引
		timer = 0;
		idx_frame++;
		// 检查当前帧索引是否到达图集尾部

	
		if (idx_frame >= atlas->GetSize())
		{
			// 如果到达图集尾部
			// 如果设置循环,则从头开始播放
			// 如果没有设置循环,则停留在动画图集的最后一帧(张)
			idx_frame = is_loop ? 0 : atlas->GetSize() - 1;

			if (!is_loop && callback)	// 如果没有设置循环播放且回调函数存在
				callback();				// 则执行回调函数的功能
		}
		
	}
}

// 动画绘制方法
void Animation::OnDraw(int x, int y)const
{
	// 渲染图片
	PutImage(x, y, atlas->GetImage(idx_frame));
}

// 回调函数
void Animation::SetCallBack(std::function<void()> callback)
{
	this->callback = callback;
}

