#include <iostream>			// c++��׼�������
#include <fstream>			// �ļ���
#include <cstdio>			// c��׼�������
#include <vector>			// vector����
#include <cstring>			// �ַ�������
#include <graphics.h>		// easyX���
#include "data.h"
#include <algorithm>

using namespace std;

vector<Data> data_list;							// ������������,�����洢���е��������
Data* current_data = nullptr;
int current_idx = 0;
Data* current_rank_data = nullptr;
//int rank_num = 0;//���а�����
vector<Data>rank_list[9];//ʮ����
int current_score = 0;//������Ϸ��ҵ÷�
int current_level = 0;//���ֹؿ���
extern const int RANKPAGE;

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

	// �������(���ڼ��)
	/*if (!data_list.empty())
	{
		for (int i = 0; i < data_list.size(); i++) {
			printf("%d:   �������:%s     �����ؿ�:%d\n", i, data_list[i].name, data_list[i].unlocked_level);
		}
	}*/

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

void ReadRankData() {
	ifstream ifs;
	ifs.open("rank_file.bin", ios::in | ios::binary);

	Data data;
	//// ������а�
	//for (int i = 0; i < RANKPAGE; ++i) {
	//	rank_list[i].clear();
	//}
	// ��ȡ����������,����������
	// ֱ����ȡ������
	for (int i = 0; i < RANKPAGE; i++) {
		while (ifs.read(reinterpret_cast<char*>(&data), sizeof(Data)))
		{
			rank_list[i].push_back(data);
		}
	}
	// �������(���ڼ��)
	cout << "Rank list size: " << rank_list[current_level].size() << endl;
	for (auto& rank : rank_list[current_level]) {
		cout << "Player: " << rank.name << ", Score: " << rank.level_score[current_level] << endl;
	}
	ifs.close();
}

bool cmp(struct Data& a, struct Data& b) {
	return  a.level_score[current_level] > b.level_score[current_level];
}

void WriteRankData() {
	//�ڸ������а�ʱ���轫֮ǰ�����а���գ��ٸ�������д�루��δд��,rank_list�����������Ѹ���
	ofstream ofs;
	ofs.open("rank_file.bin", ios::out | ios::binary);
	sort(rank_list[current_level].begin(), rank_list[current_level].end(), cmp);
	//��rank_listд���ļ�
	for (int i = 0; i < RANKPAGE; i++) {
		if (!rank_list[i].empty())
		{
			for (const auto& player_data : rank_list[i])
			{
				ofs.write(reinterpret_cast<const char*>(&player_data), sizeof(Data));
			}
		}
	}
	ofs.close();
}
