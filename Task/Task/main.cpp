#include <time.h>
#include "main.h"

#define JUDGE_TYPE_MAX 3
// ���̒�`
JudgeInfo m_JudgeInfo;

std::map<JudgeType, JudgeInfo> m_judge =
{
	{ Win,	JudgeInfo{ "����" ,0 } },
	{ Lose,	JudgeInfo{ "����" ,0 } },
	{ Draw,	JudgeInfo{ "��������" ,0 } },
};

enum AttackTYPE
{
	Rock = 1,	// �O�[
	Scissors,	// �`���L
	Paper,		// �p�[
	TYPE_MAX,
};

// ���O
const std::map<AttackTYPE, std::string> m_name =
{
	{ Rock,		"�O�[" },
	{ Scissors,	"�`���L" },
	{ Paper,	"�p�[" },
};
// ���s[�v���C���[][CPU]
JudgeType m_judgeType[JUDGE_TYPE_MAX][JUDGE_TYPE_MAX] =
{
	{ Draw,Win,Lose },	// �O�[ 
	{ Lose,Draw,Win },	// �`���L
	{ Win,Lose,Draw },	// �p�[ 
};

//������������
JudgeType WinLoseJudge(AttackTYPE player, AttackTYPE enemy)
{
	return m_judgeType[player - 1][enemy - 1];
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
		printf("�v���C���[��%s��I�����܂���\n", m_name.at((AttackTYPE)player).c_str());
		printf("�����%s��I�����܂���\n", m_name.at((AttackTYPE)enemy).c_str());
		
		JudgeType judge = WinLoseJudge((AttackTYPE)player, (AttackTYPE)enemy);
		// �J�E���g���₷
		m_judge[(JudgeType)judge].count += 1;
		
		// ������������
		printf("%s\n", m_judge[(JudgeType)judge].name.c_str());

		// ���
		printf("����%d ����%d ��������%d\n\n", m_judge[Win].count, m_judge[Lose].count, m_judge[Draw].count);
	}
}








