#pragma once
/*
	������:ja1u0va
	����:
		1.
		2.
	ʾ��:
		1.



*/

#include <vector>
#include <graphics.h>


class Atlas {
private:
	std::vector<IMAGE> img_list;

public:
	Atlas() = default;
	~Atlas() = default;

	// ���ļ��е���ͼƬ�زķ���
	void LoadFromFile(LPCTSTR path_template, int num);

	// ���ͼ������
	void Clear();

	// �õ�ͼ����С����(����֪�ж�����ͼƬ)
	int GetSize();

	// �õ�ͼ���е�ĳһ��ͼƬ
	IMAGE* GetImage(int idx);

	// ����ͼƬ����
	void AddImage(const IMAGE& img);
};