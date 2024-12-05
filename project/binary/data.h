#pragma once
#include <vector>

struct Data 
{
	char name[12] = "xcpcer";					// 玩家名字
	int unlocked_level = 0;						// 解锁的关卡数
	bool unlocked_achievement[12] = { false };	// 解锁成就
	int level_score[11][3] = { 0 };				// 对应每关的分数,每个玩家每一关记录三次

	int num_AC = 0;
	int num_WA = 0;
	int num_death = 0;
	int num_CE = 0;
	int num_TLE = 0;
	int num_MLE = 0;
	int num_opposite = 0;
	int num_bounce = 0;
	int num_speed = 0;

	// 重载==运算符
	bool operator==(const Data& other) const
	{
		if (strcmp(name, other.name) != 0)		       // 比较名字
			return false;

		if (unlocked_level != other.unlocked_level)    // 比较解锁的关卡数
			return false;

		return true;
	}

	// 更新成就
	void UpdateAchievement()
	{
		// 0 自由落体          从底部脱离了这个世界
		if (num_death >= 1)
		{
			unlocked_achievement[0] = true;
		}

		// 1 我是谁，我在哪     出栈(即第一次死亡)
		if (num_death >= 1)
		{
			unlocked_achievement[1] = true;
		}

		// 2 盖亚！！          踩上CE
		if (num_CE >= 1)
		{
			unlocked_achievement[2] = true;
		}

		// 3 made in heaven   跳上3次[TLE]
		if (num_TLE >= 3)
		{
			unlocked_achievement[3] = true;
		}

		// 4 世界真小          跳上3次[MLE]
		if (num_MLE >= 3)
		{
			unlocked_achievement[4] = true;
		}

		// 5 左右互博          跳上3次[opposite]
		if (num_opposite >= 3)
		{
			unlocked_achievement[5] = true;
		}

		// 6 芜湖起飞          跳上3次[bounce]
		if (num_bounce >= 3)
		{
			unlocked_achievement[6] = true;
		}

		// 7 闪电神经          跳上3次[speed]
		if (num_speed >= 3)
		{
			unlocked_achievement[7] = true;
		}

		// 8 洛谷集邮          踩过了所有报错平台
		if (num_TLE && num_MLE && num_CE && num_WA)
		{
			unlocked_achievement[8] = true;
		}

		// 9 GrandMaster      获得全部成就
		unlocked_achievement[9] = true;
		for (int i = 0;i < 20;i++)
		{
			if (unlocked_achievement[i] == false)
			{
				unlocked_achievement[9] = false;
				break;
			}
		}

		// 10 天选不死人       死亡了20次
		if (num_death >= 20)
		{
			unlocked_achievement[10] = true;
		}


		// 11 部分正确         跳上20次WA
		if (num_death >= 20)
		{
			unlocked_achievement[11] = true;
		}

	}
};



// -----成就与数字的对应-----
// 0 自由落体          从底部脱离了这个世界
// 1 我是谁，我在哪     出栈(即第一次死亡)
// 2 盖亚！！          踩上CE
// 3 made in heaven   跳上3次[TLE]
// 4 世界真小          跳上3次[MLE]
// 5 左右互博          跳上3次[opposite]
// 6 芜湖起飞          跳上3次[bounce]
// 7 闪电神经          跳上3次[speed]
// 8 洛谷集邮          踩过了所有平台
// 9 GrandMaster      获得全部成就
// 10 天选不死人       死亡了20次
// 11 部分正确         跳上20次WA
// 12 成为代码         获得积分1000



/*
	for (int i = rank[page].size();i >= 0;i--)
	{
		int idx = rank[page].size() - i;
		_stprintf_s(text, _T("%d"), rank[page][i].score);
		outtextxy(115, idx*20+235, text);
	}
*/