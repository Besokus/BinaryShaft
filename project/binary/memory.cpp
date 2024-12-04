#include <iostream>			// c++��׼�������
#include <fstream>			// �ļ���
#include <cstdio>			// c��׼�������
#include <vector>			// vector����
#include <cstring>			// �ַ�������
#include <graphics.h>		// easyX���
#include "data.h"

using namespace std;

vector<Data> data_list;							// ������������,�����洢���е��������
Data* current_data = nullptr;
int current_idx = 0;

// ��ȡ�ļ������ݵĺ���,������data_list
void ReadData()
{
	ifstream ifs;
	ifs.open("memory_file.bin", ios::in | ios::binary);

	Data data;

	// ��ȡ����������,����������
	// ֱ����ȡ������
	while (ifs.read(reinterpret_cast<char*>(&data), sizeof(Data))) 
	{
		data_list.push_back(data);
	}

	ifs.close();
}

// ��data_list�е�����д���ļ�
void WriteData() 
{
	ofstream ofs;
	ofs.open("memory_file.bin", ios::out | ios::binary);

	if (!data_list.empty()) 
	{
		for (const auto& player_data : data_list)
		{
			ofs.write(reinterpret_cast<const char*>(&player_data), sizeof(Data));
		}
	}

	ofs.close();
}


void ClearData()
{
	data_list.clear();
}
