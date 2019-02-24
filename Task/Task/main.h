#ifndef _MAIN_H
#define _MAIN_H

#include <map>

// ���������֌W
enum JudgeType
{
	Win,	// ����
	Lose,	// ����
	Draw,	// ��������
};
struct JudgeInfo
{
	std::string name = "";
	int count = 0;
	JudgeInfo() {};
	JudgeInfo(std::string _name, int _count)
	{
		name = _name;
		count = _count;
	}
};
extern JudgeInfo m_JudgeInfo;
extern std::map<JudgeType, JudgeInfo> m_judge;

#endif