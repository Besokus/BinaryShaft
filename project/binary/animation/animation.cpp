#include "animation.h"

extern void PutImage(int x, int y, IMAGE* img);

// ���ö���״̬
// ��������Ҫ��ͷ����ʱʹ��
void Animation::Reset()
{
	timer = 0;
	idx_frame = 0;
}

// ���ö�����ʹ�õ�ͼ��
void Animation::SetAtlas(Atlas* new_atlas)
{
	// Ϊ�˱����ظ����ò�����֡����Խ��
	// ����Reset���ö���
	Reset();
	atlas = new_atlas;
}

// �����Ƿ�ѭ�����Ŷ���
void Animation::SetLoop(bool flag)
{
	is_loop = flag;
}

// ����֡�����
void Animation::SetInterval(int ms)
{
	interval = ms;
}

// ��ȡ��ǰ֡����
int Animation::GetIdxFrame()
{
	return idx_frame;
}

// ��ȡ��ǰ֡ͼƬ
IMAGE* Animation::GetFrame()
{
	return atlas->GetImage(idx_frame);
}

// ��鶯���Ƿ񲥷Ž���
bool Animation::CheckFinished()
{
	// ������������Ϊѭ������ʱ,����Զ���Ქ�Ž���
	if (is_loop) return false;

	// ��֮,��鵱ǰ֡�����Ƿ񵽴�ͼ����β��
	return (idx_frame == atlas->GetSize() - 1);
}

// �������·���
void Animation::OnUpDate(int delta)
{
	// ÿ�θ���ʱ��鶨ʱ����ֵ
	timer += delta;
	// ��鶨ʱ����ֵ�Ƿ񵽴�֡���
	if (timer >= interval)
	{
		// �������֡���
		// ���ü�ʱ��,���ۼ�֡����
		timer = 0;
		idx_frame++;
		// ��鵱ǰ֡�����Ƿ񵽴�ͼ��β��

	
		if (idx_frame >= atlas->GetSize())
		{
			// �������ͼ��β��
			// �������ѭ��,���ͷ��ʼ����
			// ���û������ѭ��,��ͣ���ڶ���ͼ�������һ֡(��)
			idx_frame = is_loop ? 0 : atlas->GetSize() - 1;

			if (!is_loop && callback)	// ���û������ѭ�������һص���������
				callback();				// ��ִ�лص������Ĺ���
		}
		
	}
}

// �������Ʒ���
void Animation::OnDraw(int x, int y)const
{
	// ��ȾͼƬ
	PutImage(x, y, atlas->GetImage(idx_frame));
}

// �ص�����
void Animation::SetCallBack(std::function<void()> callback)
{
	this->callback = callback;
}

