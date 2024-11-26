/*
	������:ja1u0va
	ʹ��˵��:һЩ����ͼƬ�ļ��ĺ���
	����:




*/


#include <graphics.h>
#include "../../atlas/atlas.h"

#pragma comment(lib,"MSIMG32.LIB")// ���ӵ��ض��Ŀ�

// ��תͼƬ�ĺ���
// Ӧ�ô˺���,ֻ����Ⱦһ�������ͼƬ�ز�
// src��תǰ��ԭͼƬ  dst��ת���Ŀ��ͼƬ
void FlipImage(IMAGE* src, IMAGE* dst)
{
	int w = src->getwidth();
	int h = src->getheight();
	Resize(dst, w, h);
	DWORD* src_buffer = GetImageBuffer(src);
	DWORD* dst_buffer = GetImageBuffer(dst);
	for (int y = 0;y < h;y++)
	{
		for (int x = 0;x < w;x++)
		{
			int idx_src = y * w + x;
			int idx_dst = y * w + (w - x - 1);
			dst_buffer[idx_dst] = src_buffer[idx_src];
		}
	}
}

// ��תͼ������
void FlipAtlas(Atlas& src, Atlas& dst)
{
	dst.Clear();
	for (int i = 0;i < src.GetSize();i++)
	{
		IMAGE img_flpipped;
		FlipImage(src.GetImage(i), &img_flpipped);
		dst.AddImage(img_flpipped);
	}

}

// ����������Ⱦ��͸��ͼ���ͼƬ�ĺ���
void PutImage(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}