#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>


using namespace std;
enum AttackTYPE
{
	Rock = 1,	// グー
	Scissors,	// チョキ
	Paper,		// パー
	TYPE_MAX,
};
// 名前
map<AttackTYPE, string> m_name =
{
	{ Rock,		"グー" },
	{ Scissors,	"チョキ" },
	{ Paper,	"パー" },
};

// 相性
map<AttackTYPE, AttackTYPE> m_typeMap =
{
	{ Rock,		Scissors },
	{ Scissors,	Paper },
	{ Paper,	Rock },
};

// 勝ち負け関係
enum JudgeType
{
	Win,	// 勝ち
	Lose,	// 負け
	Draw,	// 引き分け
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
	{ Win,	JudgeInfo{ "勝ち" ,0 } },
	{ Lose,	JudgeInfo{ "負け" ,0 } },
	{ Draw,	JudgeInfo{ "引き分け" ,0 } },
};
