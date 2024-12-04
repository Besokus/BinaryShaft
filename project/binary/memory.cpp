#include <iostream>			// c++标准输入输出
#include <fstream>			// 文件流
#include <cstdio>			// c标准输入输出
#include <vector>			// vector链表
#include <cstring>			// 字符串函数
#include <graphics.h>		// easyX相关
#include "data.h"
#include <algorithm>

using namespace std;

vector<Data> data_list;							// 定义数据链表,用来存储现有的玩家数据
Data* current_data = nullptr;
int current_idx = 0;
Data* current_rank_data = nullptr;
//int rank_num = 0;//排行榜人数
vector<Data>rank_list[9];//十个榜单
int current_score = 0;//本轮游戏玩家得分
int current_level = 0;//本轮关卡数
extern const int RANKPAGE;

// 读取文件中数据的函数,并存入data_list
void ReadData()
{
	ifstream ifs;
	ifs.open("memory_file.bin", ios::in | ios::binary);

	Data data;

	// 读取文中中数据,并存入链表
	// 直到读取完数据
	while (ifs.read(reinterpret_cast<char*>(&data), sizeof(Data))) 
	{
		data_list.push_back(data);
	}

	// 输出数据(用于检查)
	/*if (!data_list.empty())
	{
		for (int i = 0; i < data_list.size(); i++) {
			printf("%d:   玩家姓名:%s     解锁关卡:%d\n", i, data_list[i].name, data_list[i].unlocked_level);
		}
	}*/

	ifs.close();
}

// 将data_list中的数据写入文件
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
	//// 清空排行榜
	//for (int i = 0; i < RANKPAGE; ++i) {
	//	rank_list[i].clear();
	//}
	// 读取文中中数据,并存入链表
	// 直到读取完数据
	for (int i = 0; i < RANKPAGE; i++) {
		while (ifs.read(reinterpret_cast<char*>(&data), sizeof(Data)))
		{
			rank_list[i].push_back(data);
		}
	}
	// 输出数据(用于检查)
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
	//在更新排行榜时，需将之前的排行榜清空，再根据排序写入（还未写）,rank_list在死亡界面已更新
	ofstream ofs;
	ofs.open("rank_file.bin", ios::out | ios::binary);
	sort(rank_list[current_level].begin(), rank_list[current_level].end(), cmp);
	//将rank_list写入文件
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
