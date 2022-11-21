//[1]ヘッダーをインクルードする場所
#include <stdio.h>//標準入出力ヘッダーをインクルード
#include <stdlib.h>//標準ライブラリヘッダーをインクルードする
#include <conio.h>//コンソール入出力ヘッダーをインクルード
//[2]定数を定義する場所

//[3]列挙定数を定義する場所
//キャラクターの種類を定義
enum
{
	CHARACTER_PLAYER,	//プレイヤー
	CHARACTER_MONSTER,	//モンスター
	CHARACTER_MAX		//キャラクターの種類の数
};
//モンスターの種類を定義
enum
{
	MONSTER_PLAYER,//プレイヤー
	MONSTER_SMILE, //スライム
	MONSTER_MAX    //モンスターの種類の数
};
//コマンドの種類を定義する
enum
{
	COMMAND_FIGHT,	//戦う
	COMMAND_SPELL,	//呪文
	COMMAND_RUN,	//逃げる
	COMMAND_MAX		//コマンドの種類の数
};

//[4]構造体を宣言する場所
//キャラクターの構造体を構築
typedef struct {
	int hp;    //HP
	int maxHp; //最大HP
	int mp;    //MP
	int maxMp; //最大MP
	char name[4 * 2 + 1];//名前
	char aa[256];//アスキーアート
	int command; //コマンド
}CHRACTER;

//[5]変数を宣言する場所
//モンスターのステータスの配列を宣言する
CHRACTER monsters[MONSTER_MAX] = {
	//プレイヤー
	{
		15,			//int hp :HP
		15,			//int maxHp :最大HP
		15,			//int mp :MP
		15,			//int maxMp :最大MP
		"ゆうしゃ"  //char name[name[4 * 2 + 1]; 名前
	},

	//スライム
	{
		3,			//int hp :HP
		3,			//int maxHp :最大HP
		0,			//int mp :MP
		0,			//int maxMp :最大MP
		"スライム",  //char name[name[4 * 2 + 1]; 名前
		"／・Д・＼\n"
		"～～～～～"
	}
};

//キャラクターの配列を宣言する
CHRACTER characters[CHARACTER_MAX];

//[6]関数を宣言する場所
// ゲームを初期化する関数を宣言
void Init()
{
	//プレイヤーのステータスを初期化する
	characters[CHARACTER_PLAYER] = monsters[MONSTER_PLAYER];
}

//戦闘シーンの画面を描画する関数を宣言する
void DrawBattleScreen(){
	//画面をクリアする
	system("cls");

	//プレイヤーの名前を表示する
	printf("%s\n", characters[CHARACTER_PLAYER].name);
	//プレイヤーのステータスを表示
	printf("HP: %d/%d MP:%d/%d\n",
		characters[CHARACTER_PLAYER].hp,
		characters[CHARACTER_PLAYER].maxHp,
		characters[CHARACTER_PLAYER].mp,
		characters[CHARACTER_PLAYER].maxMp
		);

	//1行空ける
	printf("\n");

	//モンスターのアスキーアートを描画する
	printf("%s",characters[CHARACTER_MONSTER].aa);
	//モンスターのHPを表示する
	printf("(HP: %d / %d ) \n",
		characters[CHARACTER_MONSTER].hp,
		characters[CHARACTER_MONSTER].maxHp
	);

	//1行空ける
	printf("\n");

	//戦闘シーンの最初のメッセージを表示
	printf("%sが　あらわれた！\n", characters[CHARACTER_MONSTER].name);
}

//戦闘シーンの関数を宣言
void Battle(int _monster) {
	//モンスターのステータスを初期化する
	characters[CHARACTER_MONSTER] = monsters[_monster];
	//戦闘シーンの画面を描画する関数を呼び出す
	DrawBattleScreen();
	//キーボード入力を待つ
	_getch();

	//戦闘が終了するまでループする
	while (1)
	{
		//各キャラクターを反復する
		for (int i = 0; i < CHARACTER_MAX; i++)
		{
			//戦闘シーンの画面を描画する関数を呼び出す
			DrawBattleScreen();

			//選択されたコマンドで分岐する
			switch (characters[i].command)
			{
			case COMMAND_FIGHT:	//戦う
				//攻撃するメッセージを表示
				printf("%sの　こうげき！\n", characters[i].name);
				break;
			case COMMAND_SPELL:	//呪文
				break;
			case COMMAND_RUN:	//逃げる
				break;
			}
		}
	}
}

//プログラムの実行開始を宣言
int main() {
	//ゲームを初期化する変数を呼び出す
	Init();
	//戦闘シーンの関数を呼び出す
	Battle(MONSTER_SMILE);
}


