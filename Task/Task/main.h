#ifndef _MAIN_H
#define _MAIN_H

#include <map>

enum AttackTYPE
{
	None,
	Rock,	// グー
	Scissors,	// チョキ
	Paper,		// パー
	TYPE_MAX,
};

// 勝ち負け関係
enum JudgeType
{
	Win,	// 勝ち
	Lose,	// 負け
	Draw,	// 引き分け
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
	// カウント加算
	void AddCount(int index) { count += index; }
	// カウント取得
	int GetCount() { return count; }
	// なまえしゅとく
	std::string GetName() { return name; }
private:
	std::string name = "";
	int count = 0;
};

#endif