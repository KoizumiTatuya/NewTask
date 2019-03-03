#ifndef _MAIN_H
#define _MAIN_H

#include <map>

enum AttackTYPE
{
	None,
	Rock,	// �O�[
	Scissors,	// �`���L
	Paper,		// �p�[
	TYPE_MAX,
};

// ���������֌W
enum JudgeType
{
	Win,	// ����
	Lose,	// ����
	Draw,	// ��������
};

class JudgeInfo
{
public:
	JudgeInfo() {};
	~JudgeInfo() {};

	JudgeInfo(std::string _name, int _count)
	{
		name = _name;
		count = _count;
	}
	// �J�E���g���Z
	void AddCount(int index) { count += index; }
	// �J�E���g�擾
	int GetCount() { return count; }
	// �Ȃ܂�����Ƃ�
	std::string GetName() { return name; }
private:
	std::string name = "";
	int count = 0;
};

#endif