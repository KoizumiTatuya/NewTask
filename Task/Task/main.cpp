#include <time.h>
#include "main.h"

std::map<JudgeType, JudgeInfo> g_judge =
{
	{ Win,	JudgeInfo{ "勝ち" ,0 } },
	{ Lose,	JudgeInfo{ "負け" ,0 } },
	{ Draw,	JudgeInfo{ "引き分け" ,0 } },
};

// 名前
const std::map<AttackTYPE, std::string> g_name =
{
	{ Rock,		"グー" },
	{ Scissors,	"チョキ" },
	{ Paper,	"パー" },
};
// 勝敗[プレイヤー][CPU]
JudgeType g_judgeType[TYPE_MAX - 1][TYPE_MAX - 1] =
{
	{ Draw,Win,Lose },	// グー 
	{ Lose,Draw,Win },	// チョキ
	{ Win,Lose,Draw },	// パー 
};

//勝ち負け判定
JudgeType WinLoseJudge(AttackTYPE player, AttackTYPE enemy)
{
	return g_judgeType[player - 1][enemy - 1];
}

int main()
{
	srand((unsigned)time(NULL));
	char buf[100];
	int player;
	int enemy;
	while (true)
	{
		printf("1:グー 2:チョキ 3:パー\n");
		fgets(buf, 10, stdin);
		// 変換
		player = atoi(buf);
		// 文字列判定
		switch ((AttackTYPE)player)
		{
		case Rock:
		case Scissors:
		case Paper:
			break;
		default:
			printf("1から3以外の値が入力されました。\n");
			continue;
			break;
		}

		// 相手の手
		enemy = rand() % (TYPE_MAX - 1) + 1;

		// 選択したやつ
		printf("プレイヤーは%sを選択しました\n", g_name.at((AttackTYPE)player).c_str());
		printf("相手は%sを選択しました\n", g_name.at((AttackTYPE)enemy).c_str());
		
		JudgeType judge = WinLoseJudge((AttackTYPE)player, (AttackTYPE)enemy);
		// カウント増やす
		g_judge[(JudgeType)judge].AddCount(1);
		
		// 勝ち負け判定
		printf("%s\n", g_judge[(JudgeType)judge].GetName().c_str());

		// 戦績
		printf("勝ち%d 負け%d 引き分け%d\n\n", g_judge[Win].GetCount(), g_judge[Lose].GetCount(), g_judge[Draw].GetCount());
	}
}








