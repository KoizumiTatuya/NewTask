#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>


using namespace std;
enum AttackTYPE
{
	Rock = 1,	// �O�[
	Scissors,	// �`���L
	Paper,		// �p�[
	TYPE_MAX,
};
// ���O
map<AttackTYPE, string> m_name =
{
	{ Rock,		"�O�[" },
	{ Scissors,	"�`���L" },
	{ Paper,	"�p�[" },
};

// ����
map<AttackTYPE, AttackTYPE> m_typeMap =
{
	{ Rock,		Scissors },
	{ Scissors,	Paper },
	{ Paper,	Rock },
};

// ���������֌W
enum JudgeType
{
	Win,	// ����
	Lose,	// ����
	Draw,	// ��������
};
struct JudgeInfo
{
	string name = "";
	int count = 0;
	JudgeInfo() {};
	JudgeInfo(string _name, int _count)
	{
		name = _name;
		count = _count;
	}
};
map<JudgeType, JudgeInfo> m_judgeInfo =
{
	{ Win,	JudgeInfo{ "����" ,0 } },
	{ Lose,	JudgeInfo{ "����" ,0 } },
	{ Draw,	JudgeInfo{ "��������" ,0 } },
};
