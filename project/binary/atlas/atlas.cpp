#include "atlas.h"

extern const int PLAYER_WIDTH;
extern const int PLAYER_HEIGHT;

void Atlas::LoadFromFile(LPCTSTR path_template, int num)
{
	img_list.clear();
	img_list.resize(num);

	TCHAR path_file[256];
	for (size_t i = 0;i < num;i++)
	{
		_stprintf_s(path_file, path_template, i + 1);

		loadimage(&img_list[i], path_file, PLAYER_WIDTH, PLAYER_HEIGHT);
	}

}

void Atlas::Clear()
{
	img_list.clear();
}

int Atlas::GetSize()
{
	return (int)img_list.size();
}

IMAGE* Atlas::GetImage(int idx)
{
	if (idx < 0 || idx >= img_list.size())
		return nullptr;

	return &img_list[idx];
}

void Atlas::AddImage(const IMAGE& img)
{
	img_list.push_back(img);
}
