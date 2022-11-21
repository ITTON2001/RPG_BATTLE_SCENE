//[1]�w�b�_�[���C���N���[�h����ꏊ
#include <stdio.h>//�W�����o�̓w�b�_�[���C���N���[�h
#include <stdlib.h>//�W�����C�u�����w�b�_�[���C���N���[�h����
#include <conio.h>//�R���\�[�����o�̓w�b�_�[���C���N���[�h
//[2]�萔���`����ꏊ

//[3]�񋓒萔���`����ꏊ
//�L�����N�^�[�̎�ނ��`
enum
{
	CHARACTER_PLAYER,	//�v���C���[
	CHARACTER_MONSTER,	//�����X�^�[
	CHARACTER_MAX		//�L�����N�^�[�̎�ނ̐�
};
//�����X�^�[�̎�ނ��`
enum
{
	MONSTER_PLAYER,//�v���C���[
	MONSTER_SMILE, //�X���C��
	MONSTER_MAX    //�����X�^�[�̎�ނ̐�
};
//�R�}���h�̎�ނ��`����
enum
{
	COMMAND_FIGHT,	//�키
	COMMAND_SPELL,	//����
	COMMAND_RUN,	//������
	COMMAND_MAX		//�R�}���h�̎�ނ̐�
};

//[4]�\���̂�錾����ꏊ
//�L�����N�^�[�̍\���̂��\�z
typedef struct {
	int hp;    //HP
	int maxHp; //�ő�HP
	int mp;    //MP
	int maxMp; //�ő�MP
	char name[4 * 2 + 1];//���O
	char aa[256];//�A�X�L�[�A�[�g
	int command; //�R�}���h
}CHRACTER;

//[5]�ϐ���錾����ꏊ
//�����X�^�[�̃X�e�[�^�X�̔z���錾����
CHRACTER monsters[MONSTER_MAX] = {
	//�v���C���[
	{
		15,			//int hp :HP
		15,			//int maxHp :�ő�HP
		15,			//int mp :MP
		15,			//int maxMp :�ő�MP
		"�䂤����"  //char name[name[4 * 2 + 1]; ���O
	},

	//�X���C��
	{
		3,			//int hp :HP
		3,			//int maxHp :�ő�HP
		0,			//int mp :MP
		0,			//int maxMp :�ő�MP
		"�X���C��",  //char name[name[4 * 2 + 1]; ���O
		"�^�E�D�E�_\n"
		"�`�`�`�`�`"
	}
};

//�L�����N�^�[�̔z���錾����
CHRACTER characters[CHARACTER_MAX];

//[6]�֐���錾����ꏊ
// �Q�[��������������֐���錾
void Init()
{
	//�v���C���[�̃X�e�[�^�X������������
	characters[CHARACTER_PLAYER] = monsters[MONSTER_PLAYER];
}

//�퓬�V�[���̉�ʂ�`�悷��֐���錾����
void DrawBattleScreen(){
	//��ʂ��N���A����
	system("cls");

	//�v���C���[�̖��O��\������
	printf("%s\n", characters[CHARACTER_PLAYER].name);
	//�v���C���[�̃X�e�[�^�X��\��
	printf("HP: %d/%d MP:%d/%d\n",
		characters[CHARACTER_PLAYER].hp,
		characters[CHARACTER_PLAYER].maxHp,
		characters[CHARACTER_PLAYER].mp,
		characters[CHARACTER_PLAYER].maxMp
		);

	//1�s�󂯂�
	printf("\n");

	//�����X�^�[�̃A�X�L�[�A�[�g��`�悷��
	printf("%s",characters[CHARACTER_MONSTER].aa);
	//�����X�^�[��HP��\������
	printf("(HP: %d / %d ) \n",
		characters[CHARACTER_MONSTER].hp,
		characters[CHARACTER_MONSTER].maxHp
	);

	//1�s�󂯂�
	printf("\n");

	//�퓬�V�[���̍ŏ��̃��b�Z�[�W��\��
	printf("%s���@�����ꂽ�I\n", characters[CHARACTER_MONSTER].name);
}

//�퓬�V�[���̊֐���錾
void Battle(int _monster) {
	//�����X�^�[�̃X�e�[�^�X������������
	characters[CHARACTER_MONSTER] = monsters[_monster];
	//�퓬�V�[���̉�ʂ�`�悷��֐����Ăяo��
	DrawBattleScreen();
	//�L�[�{�[�h���͂�҂�
	_getch();

	//�퓬���I������܂Ń��[�v����
	while (1)
	{
		//�e�L�����N�^�[�𔽕�����
		for (int i = 0; i < CHARACTER_MAX; i++)
		{
			//�퓬�V�[���̉�ʂ�`�悷��֐����Ăяo��
			DrawBattleScreen();

			//�I�����ꂽ�R�}���h�ŕ��򂷂�
			switch (characters[i].command)
			{
			case COMMAND_FIGHT:	//�키
				//�U�����郁�b�Z�[�W��\��
				printf("%s�́@���������I\n", characters[i].name);
				break;
			case COMMAND_SPELL:	//����
				break;
			case COMMAND_RUN:	//������
				break;
			}
		}
	}
}

//�v���O�����̎��s�J�n��錾
int main() {
	//�Q�[��������������ϐ����Ăяo��
	Init();
	//�퓬�V�[���̊֐����Ăяo��
	Battle(MONSTER_SMILE);
}


