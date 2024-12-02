#pragma once
#include <vector>

// 创建存放数据的结构体
#pragma pack(push, 1)							// 禁用结构体对齐
struct Data {
	char name[10] = "xcpcer";					// 玩家名字
	int unlocked_level = 0;						// 解锁的关卡数
	bool unlocked_achievement[20] = { false };	// 解锁成就
	int level_score[11] = { 0 };				// 对应每关的分数

	// 重载==运算符
	bool operator==(const Data& other) const {
		// 比较名字
		if (strcmp(name, other.name) != 0)
			return false;

		// 比较解锁的关卡数
		if (unlocked_level != other.unlocked_level) 
			return false;

		// 如果所有成员都相等，则返回true
		return true;
	}

};
#pragma pack(pop)								// 恢复默认对齐