#pragma once
#include <vector>

struct Data {
	char name[12] = "xcpcer";					// �������
	int unlocked_level = 0;						// �����Ĺؿ���
	bool unlocked_achievement[20] = { false };	// �����ɾ�
	int level_score[11] = { 0 };				// ��Ӧÿ�صķ���

	int num_AC = 0;
	int num_WA = 0;
	int num_death = 0;
	int num_CE = 0;
	int num_TLE = 0;
	int num_MLE = 0;
	int num_opposite = 0;
	int num_bounce = 0;
	int num_speed = 0;

	// ����==�����
	bool operator==(const Data& other) const {
		// �Ƚ�����
		if (strcmp(name, other.name) != 0)
			return false;

		// �ȽϽ����Ĺؿ���
		if (unlocked_level != other.unlocked_level)
			return false;

		// ������г�Ա����ȣ��򷵻�true
		return true;
	}

	void UpdateAchievement()
	{
		// 1 ����˭��������     ��ջ(����һ������)
		if (num_death >= 1)
		{
			unlocked_achievement[1] = true;
		}

		// 2 ���ǣ���          ����CE
		if (num_CE >= 0)
		{
			unlocked_achievement[2] = true;
		}

		// 3 made in heaven   ����3��[TLE]
		if (num_TLE >= 3)
		{
			unlocked_achievement[3] = true;
		}

		// 3 made in heaven   ����3��[TLE]
		if (num_TLE >= 3)
		{
			unlocked_achievement[3] = true;
		}

		// 4 ������С          ����3��[MLE]
		if (num_MLE >= 3)
		{
			unlocked_achievement[4] = true;
		}

		// 5 ���һ���          ����3��[opposite]
		if (num_opposite >= 3)
		{
			unlocked_achievement[5] = true;
		}

		// 6 �ߺ����          ����3��[bounce]
		if (num_bounce >= 3)
		{
			unlocked_achievement[6] = true;
		}

		// 7 ������          ����3��[speed]
		if (num_speed >= 3)
		{
			unlocked_achievement[7] = true;
		}

		// 8 ��ȼ���          �ȹ������б���ƽ̨
		if (num_TLE && num_MLE && num_CE && num_WA)
		{
			unlocked_achievement[7] = true;
		}

		// 9 GrandMaster      ���ȫ���ɾ�
		unlocked_achievement[9] = true;
		for (int i = 0;i < 20;i++)
		{
			if (unlocked_achievement[i] == false)
			{
				unlocked_achievement[9] = false;
				break;
			}
		}

		// 10 ��ѡ������       ������20��
		if (num_death >= 20)
		{
			unlocked_achievement[10] = true;
		}

		
		// 11 ������ȷ         ����20��WA
		if (num_death >= 20)
		{
			unlocked_achievement[11] = true;
		}

		// 12 ������ȷ         ��û���1000
		//if ()
		{
			unlocked_achievement[12] = true;
		}
	}
};



// -----�ɾ������ֵĶ�Ӧ-----
// 0 ��������          �ӵײ��������������
// 1 ����˭��������     ��ջ(����һ������)
// 2 ���ǣ���          ����CE
// 3 made in heaven   ����3��[TLE]
// 4 ������С          ����3��[MLE]
// 5 ���һ���          ����3��[opposite]
// 6 �ߺ����          ����3��[bounce]
// 7 ������          ����3��[speed]
// 8 ��ȼ���          �ȹ�������ƽ̨
// 9 GrandMaster      ���ȫ���ɾ�
// 10 ��ѡ������       ������20��
// 11 ������ȷ         ����20��WA
// 12 ��Ϊ����         ��û���1000