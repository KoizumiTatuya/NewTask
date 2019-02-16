#include "main.h"



//������������
JudgeType WinLoseJudge(AttackTYPE p, AttackTYPE e)
{
	// �f�t�H���g�͈�������
	JudgeType type = Draw;
	// ������������
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
		printf("�v���C���[��%s��I�����܂���\n", m_name[(AttackTYPE)player].c_str());
		printf("�����%s��I�����܂���\n", m_name[(AttackTYPE)enemy].c_str());
		
		JudgeType judge = WinLoseJudge((AttackTYPE)player, (AttackTYPE)enemy);
		// �J�E���g���₷
		m_judgeInfo[(JudgeType)judge].count += 1;
		
		// ������������
		printf("%s\n", m_judgeInfo[(JudgeType)judge].name.c_str());

		// ���
		printf("����%d ����%d ��������%d\n\n", m_judgeInfo[Win].count, m_judgeInfo[Lose].count, m_judgeInfo[Draw].count);
	}
}








