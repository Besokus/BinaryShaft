/*
	负责人:ja1u0va
	使用说明:一些处理图片文件的函数
	例子:




*/


#include <graphics.h>
#include "../../atlas/atlas.h"

#pragma comment(lib,"MSIMG32.LIB")// 链接到特定的库

// 翻转图片的函数
// 应用此函数,只需渲染一个方向的图片素材
// src翻转前的原图片  dst翻转后的目标图片
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

// 翻转图集函数
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

// 用来正常渲染含透明图层的图片的函数
void PutImage(int x, int y, IMAGE* img)
{
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER,0,255,AC_SRC_ALPHA });
}