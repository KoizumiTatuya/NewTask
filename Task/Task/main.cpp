#include <time.h>
#include "main.h"

std::map<JudgeType, JudgeInfo> g_judge =
{
	{ Win,	JudgeInfo{ "����" ,0 } },
	{ Lose,	JudgeInfo{ "����" ,0 } },
	{ Draw,	JudgeInfo{ "��������" ,0 } },
};

// ���O
const std::map<AttackTYPE, std::string> g_name =
{
	{ Rock,		"�O�[" },
	{ Scissors,	"�`���L" },
	{ Paper,	"�p�[" },
};
// ���s[�v���C���[][CPU]
JudgeType g_judgeType[TYPE_MAX - 1][TYPE_MAX - 1] =
{
	{ Draw,Win,Lose },	// �O�[ 
	{ Lose,Draw,Win },	// �`���L
	{ Win,Lose,Draw },	// �p�[ 
};

//������������
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
		printf("1:�O�[ 2:�`���L 3:�p�[\n");
		fgets(buf, 10, stdin);
		// �ϊ�
		player = atoi(buf);
		// �����񔻒�
		switch ((AttackTYPE)player)
		{
		case Rock:
		case Scissors:
		case Paper:
			break;
		default:
			printf("1����3�ȊO�̒l�����͂���܂����B\n");
			continue;
			break;
		}

		// ����̎�
		enemy = rand() % (TYPE_MAX - 1) + 1;

		// �I���������
		printf("�v���C���[��%s��I�����܂���\n", g_name.at((AttackTYPE)player).c_str());
		printf("�����%s��I�����܂���\n", g_name.at((AttackTYPE)enemy).c_str());
		
		JudgeType judge = WinLoseJudge((AttackTYPE)player, (AttackTYPE)enemy);
		// �J�E���g���₷
		g_judge[(JudgeType)judge].AddCount(1);
		
		// ������������
		printf("%s\n", g_judge[(JudgeType)judge].GetName().c_str());

		// ���
		printf("����%d ����%d ��������%d\n\n", g_judge[Win].GetCount(), g_judge[Lose].GetCount(), g_judge[Draw].GetCount());
	}
}








