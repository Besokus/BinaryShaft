#pragma once
#include <vector>

// ����������ݵĽṹ��
#pragma pack(push, 1)							// ���ýṹ�����
struct Data {
	char name[10] = "xcpcer";					// �������
	int unlocked_level = 0;						// �����Ĺؿ���
	bool unlocked_achievement[20] = { false };	// �����ɾ�
	int level_score[11] = { 0 };				// ��Ӧÿ�صķ���

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

};
#pragma pack(pop)								// �ָ�Ĭ�϶���