//[1]�w�b�_�[���C���N���[�h����ꏊ
#include <stdio.h>//�W�����o�̓w�b�_�[���C���N���[�h
#include <stdlib.h>//�W�����C�u�����w�b�_�[���C���N���[�h����
#include <time.h>//���ԊǗ��w�b�_�[���C���N���[�h����
#include <conio.h>//�R���\�[�����o�̓w�b�_�[���C���N���[�h
#include <string.h>//��������w�b�_�[���C���N���[�h����
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
	int attack;//�U����
	char name[4 * 2 + 1];//���O
	char aa[256];//�A�X�L�[�A�[�g
	int command; //�R�}���h
	int target;	//�U���Ώ�
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
		3,			//int attack :�U����
		"�䂤����"  //char name[name[4 * 2 + 1]; ���O
	},

	//�X���C��
	{
		3,			//int hp :HP
		3,			//int maxHp :�ő�HP
		0,			//int mp :MP
		0,			//int maxMp :�ő�MP
		2,			//int attack :�U����
		"�X���C��",  //char name[name[4 * 2 + 1]; ���O
		"�^�E�D�E�_\n"
		"�`�`�`�`�`"
	}
};

//�R�}���h�̖��O��錾����
char commandNames[COMMAND_MAX][4 * 2 + 1] = {
	"��������",	//COMMAND_FIGHT �키
	"�������", //COMMAND_SPELL ����
	"�ɂ���"	//COMMAND_RUN	������
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
}

//�R�}���h��I������֐���錾����
void SelectCommand() {
	//�R�}���h�����肳���܂Ŗ������[�v����
	while (1)
	{
		//�퓬��ʂ�`�ʂ���֐����Ăяo��
		DrawBattleScreen();
		//�R�}���h�̈ꗗ��\������
		for (int i = 0; i < COMMAND_MAX; i++) {
			//�I�𒆂̃R�}���h�̎�
			if (i == characters[CHARACTER_PLAYER].command)
			{
				//�J�[�\����`�ʂ���
				printf("��");
			}
			//�I�𒆂̃R�}���h�łȂ����
			else {
				//�S�p�X�y�[�X������
				printf("�@");
			}
			//�R�}���h�̖��O��\������
			printf("%s\n", commandNames[i]);
		}
		//���͂��ꂽ�L�[�ɂ���ĕ��򂷂�
		switch (_getch())
		{
		case 'w'://w�L�[�������ꂽ��
			//��̃R�}���h�ɐ؂�ւ���
			characters[CHARACTER_PLAYER].command--;//enum�Œ�`����command�̐��l��1���炵�Ă���
			break;
		case 's'://s�L�[�������ꂽ��
			//���̃R�}���h�ɐ؂�ւ���
			characters[CHARACTER_PLAYER].command++;//enum�Œ�`����command�̐��l��1���₵�Ă���
			break;
		default://��L�ȊO�̃L�[�������ꂽ��
			return;//�֐��𔲂���
		}

		//�J�[�\�����㉺�Ƀ��[�v������
		characters[CHARACTER_PLAYER].command =
			(COMMAND_MAX + characters[CHARACTER_PLAYER].command) % COMMAND_MAX;

	}

}

//�퓬�V�[���̊֐���錾
void Battle(int _monster) {
	//�����X�^�[�̃X�e�[�^�X������������
	characters[CHARACTER_MONSTER] = monsters[_monster];
	//�퓬�V�[���̉�ʂ�`�悷��֐����Ăяo��
	DrawBattleScreen();
	//�퓬�V�[���̍ŏ��̃��b�Z�[�W��\��
	printf("%s���@�����ꂽ�I\n", characters[CHARACTER_MONSTER].name);
	//�L�[�{�[�h���͂�҂�
	_getch();

	//�v���C���[�̍U���Ώۂ������X�^�[�ɐݒ肷��
	characters[CHARACTER_PLAYER].target = CHARACTER_MONSTER;

	//�����X�^�[�̍U���Ώۂ��v���C���[�ɐݒ肷��
	characters[CHARACTER_MONSTER].target = CHARACTER_PLAYER;

	//�퓬���I������܂Ń��[�v����
	while (1)
	{
		//�R�}���h��I������֐����Ăяo��
		SelectCommand();
		
		//�e�L�����N�^�[�𔽕�����
		for (int i = 0; i < CHARACTER_MAX; i++)
		{
			//�퓬�V�[���̉�ʂ�`�悷��֐����Ăяo��
			DrawBattleScreen();

			//�I�����ꂽ�R�}���h�ŕ��򂷂�
			switch (characters[i].command)
			{
			case COMMAND_FIGHT:	//�키
			{
				//�U�����郁�b�Z�[�W��\��
				printf("%s�́@���������I\n", characters[i].name);
				//�G�ɗ^����_���[�W���v�Z����
				int damage = 1 + rand() % characters[i].attack;
				//�G�Ƀ_���[�W��^����
				characters[characters[i].target].hp -= damage;
				//�G��HP�����̒l�ɂȂ������ǂ������肷��
				if (characters[characters[i].target].hp < 0)
				{
					//�G��HP��0�ɂ���
					characters[characters[i].target].hp = 0;
				}
				//�퓬�V�[���̉�ʂ��ĕ`�悷��֐����Ăяo��
				DrawBattleScreen();

				//�G�Ƀ_���[�W��^�������b�Z�[�W��\������
				printf("%s�Ɂ@%d�́@�_���[�W�I\n", characters[characters[i].target].name, damage);

				//�L�[�{�[�h���͂�҂�
				_getch();

				break;
			}
			case COMMAND_SPELL:	//����
				break;
			case COMMAND_RUN:	//������
				//�����o�������b�Z�[�W��\��
				printf("%s�́@�ɂ��������I\n", characters[i].name);

				//�L�[�{�[�h���͂�҂�
				_getch();

				//1/6�̊m���œ����o���̂����s�����鏈��
				int run = rand() % 6 + 1;
				//run��1�ƂȂ����Ƃ�
				if (run == 1) {
					//�����o�����s�̃��b�Z�[�W��\��
					printf("�������@�ɂ����Ȃ������E�E�E");

					//�L�[�{�[�h���͂�҂�
					_getch();

					break;
				}
				//1�ȊO�̐��l���o���Ƃ�
				else{
					//�퓬�V�[���̊֐��𔲂���i�����o�������j
					return;
				}
			}

			//�U���Ώۂ�|�������ǂ����𔻒肷��
			if (characters[characters[i].target].hp <= 0)
			{
				//�U���Ώۂɂ���ĕ��򂳂���
				switch (characters[i].target)
				{
				//�v���C���[�Ȃ�
				case CHARACTER_PLAYER:
					//�퓬�V�[���̉�ʂ��ĕ`�悷��֐����Ăяo��
					DrawBattleScreen();
					//�Q�[���I�[�o�[
					printf("%s�́@�������ꂽ�E�E�E\n", characters[characters[i].target].name);
					break;

				//�����X�^�[�Ȃ�
				case CHARACTER_MONSTER:
					//�����X�^�[�̃A�X�L�[�A�[�g�������\�����Ȃ��悤�ɏ���������
					strcpy_s(characters[characters[i].target].aa, "\n");
					//�퓬�V�[���̉�ʂ��ĕ`�悷��֐����Ăяo��
					DrawBattleScreen();
					//�����X�^�[��|�������b�Z�[�W��\������
					printf("%s���@���������I\n", characters[characters[i].target].name);

					break;
				}

				//�L�[�{�[�h���͂�҂�
				_getch();

				//�퓬�V�[���̊֐��𔲂���
				return;
			}
		}
	}
}


//�v���O�����̎��s�J�n��錾
int main() {
	//�������V���b�t������
	srand((unsigned int)time(NULL));
	//�Q�[��������������ϐ����Ăяo��
	Init();
	//�퓬�V�[���̊֐����Ăяo��
	Battle(MONSTER_SMILE);
}


