#pragma once

/*
	������:ja1u0va
	����:
		1.
		2.
	ʾ��:
		1.



*/

#include <graphics.h>
#include <functional>
#include "../atlas/atlas.h"

class Animation
{

private:
	int timer = 0;					// ��ʱ��
	int interval = 0;				// ֡���
	int idx_frame = 0;				// ֡����
	bool is_loop = true;			// �Ƿ�ѭ��
	Atlas* atlas = nullptr;			// �˶���ʹ�õ�ͼ��
	std::function<void()> callback;	// function��һ��ģ����


public:
	Animation() = default;
	~Animation() = default;

	// ���ö���״̬
	// ��������Ҫ��ͷ����ʱʹ��
	void Reset();

	// ���ö�����ʹ�õ�ͼ��
	void SetAtlas(Atlas* new_atlas);

	// �����Ƿ�ѭ�����Ŷ���
	void SetLoop(bool flag);

	// ����֡�����
	void SetInterval(int ms);

	// ��ȡ��ǰ֡����
	int GetIdxFrame();

	// ��ȡ��ǰ֡ͼƬ
	IMAGE* GetFrame();

	// ��鶯���Ƿ񲥷Ž���
	bool CheckFinished();

	// �������·���
	void OnUpDate(int delta);

	// �������Ʒ���
	void OnDraw(int x, int y)const;

	void SetCallBack(std::function<void()> callback);
};