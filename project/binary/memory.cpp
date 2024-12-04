#include <iostream>			// c++标准输入输出
#include <fstream>			// 文件流
#include <cstdio>			// c标准输入输出
#include <vector>			// vector链表
#include <cstring>			// 字符串函数
#include <graphics.h>		// easyX相关
#include "data.h"

using namespace std;

vector<Data> data_list;							// 定义数据链表,用来存储现有的玩家数据
Data* current_data = nullptr;
int current_idx = 0;

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
