#include "main.h"



//勝ち負け判定
JudgeType WinLoseJudge(AttackTYPE p, AttackTYPE e)
{
	// デフォルトは引き分け
	JudgeType type = Draw;
	// 勝ち負け判定
	type = m_typeMap[p] == e ? Win : type;
	type = m_typeMap[e] == p ? Lose : type;

	return type;
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
		printf("プレイヤーは%sを選択しました\n", m_name[(AttackTYPE)player].c_str());
		printf("相手は%sを選択しました\n", m_name[(AttackTYPE)enemy].c_str());
		
		JudgeType judge = WinLoseJudge((AttackTYPE)player, (AttackTYPE)enemy);
		// カウント増やす
		m_judgeInfo[(JudgeType)judge].count += 1;
		
		// 勝ち負け判定
		printf("%s\n", m_judgeInfo[(JudgeType)judge].name.c_str());

		// 戦績
		printf("勝ち%d 負け%d 引き分け%d\n\n", m_judgeInfo[Win].count, m_judgeInfo[Lose].count, m_judgeInfo[Draw].count);
	}
}








