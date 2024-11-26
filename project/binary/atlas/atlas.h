#pragma once
/*
	负责人:ja1u0va
	功能:
		导入图片素材,并设立为一个图集(例如玩家移动的每一帧素材)
	示例:
		Atlas* atlas_player = nullptr;
		atlas_player = new Atlas(图片路径 ,图片数量);
		
		// 其他功能,可能会用到,可以看看,应该也不难理解它的意思

*/

#include <vector>
#include <graphics.h>


class Atlas {
private:
	std::vector<IMAGE> img_list;

public:
	Atlas() = default;
	~Atlas() = default;

	// 从文件夹导入图片素材方法
	void LoadFromFile(LPCTSTR path_template, int num);

	// 清空图集方法
	void Clear();

	// 得到图集大小方法(即得知有多少张图片)
	int GetSize();

	// 得到图集中的某一张图片
	IMAGE* GetImage(int idx);

	// 加入图片方法
	void AddImage(const IMAGE& img);
};