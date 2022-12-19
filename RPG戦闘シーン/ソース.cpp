//[1]ヘッダーをインクルードする場所
#include <stdio.h>//標準入出力ヘッダーをインクルード
#include <stdlib.h>//標準ライブラリヘッダーをインクルードする
#include <time.h>//時間管理ヘッダーをインクルードする
#include <conio.h>//コンソール入出力ヘッダーをインクルード
#include <string.h>//文字操作ヘッダーをインクルードする
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
	int attack;//攻撃力
	char name[4 * 2 + 1];//名前
	char aa[256];//アスキーアート
	int command; //コマンド
	int target;	//攻撃対象
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
		3,			//int attack :攻撃力
		"ゆうしゃ"  //char name[name[4 * 2 + 1]; 名前
	},

	//スライム
	{
		3,			//int hp :HP
		3,			//int maxHp :最大HP
		0,			//int mp :MP
		0,			//int maxMp :最大MP
		2,			//int attack :攻撃力
		"スライム",  //char name[name[4 * 2 + 1]; 名前
		"／・Д・＼\n"
		"～～～～～"
	}
};

//コマンドの名前を宣言する
char commandNames[COMMAND_MAX][4 * 2 + 1] = {
	"たたかう",	//COMMAND_FIGHT 戦う
	"じゅもん", //COMMAND_SPELL 呪文
	"にげる"	//COMMAND_RUN	逃げる
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
}

//コマンドを選択する関数を宣言する
void SelectCommand() {
	//コマンドが決定されるまで無限ループする
	while (1)
	{
		//戦闘画面を描写する関数を呼び出す
		DrawBattleScreen();
		//コマンドの一覧を表示する
		for (int i = 0; i < COMMAND_MAX; i++) {
			//選択中のコマンドの時
			if (i == characters[CHARACTER_PLAYER].command)
			{
				//カーソルを描写する
				printf("＞");
			}
			//選択中のコマンドでなければ
			else {
				//全角スペースを入れる
				printf("　");
			}
			//コマンドの名前を表示する
			printf("%s\n", commandNames[i]);
		}
		//入力されたキーによって分岐する
		switch (_getch())
		{
		case 'w'://wキーが押されたら
			//上のコマンドに切り替える
			characters[CHARACTER_PLAYER].command--;//enumで定義したcommandの数値を1減らしている
			break;
		case 's'://sキーが押されたら
			//下のコマンドに切り替える
			characters[CHARACTER_PLAYER].command++;//enumで定義したcommandの数値を1増やしている
			break;
		default://上記以外のキーが押されたら
			return;//関数を抜ける
		}

		//カーソルを上下にループさせる
		characters[CHARACTER_PLAYER].command =
			(COMMAND_MAX + characters[CHARACTER_PLAYER].command) % COMMAND_MAX;

	}

}

//戦闘シーンの関数を宣言
void Battle(int _monster) {
	//モンスターのステータスを初期化する
	characters[CHARACTER_MONSTER] = monsters[_monster];
	//戦闘シーンの画面を描画する関数を呼び出す
	DrawBattleScreen();
	//戦闘シーンの最初のメッセージを表示
	printf("%sが　あらわれた！\n", characters[CHARACTER_MONSTER].name);
	//キーボード入力を待つ
	_getch();

	//プレイヤーの攻撃対象をモンスターに設定する
	characters[CHARACTER_PLAYER].target = CHARACTER_MONSTER;

	//モンスターの攻撃対象をプレイヤーに設定する
	characters[CHARACTER_MONSTER].target = CHARACTER_PLAYER;

	//戦闘が終了するまでループする
	while (1)
	{
		//コマンドを選択する関数を呼び出す
		SelectCommand();
		
		//各キャラクターを反復する
		for (int i = 0; i < CHARACTER_MAX; i++)
		{
			//戦闘シーンの画面を描画する関数を呼び出す
			DrawBattleScreen();

			//選択されたコマンドで分岐する
			switch (characters[i].command)
			{
			case COMMAND_FIGHT:	//戦う
			{
				//攻撃するメッセージを表示
				printf("%sの　こうげき！\n", characters[i].name);
				//敵に与えるダメージを計算する
				int damage = 1 + rand() % characters[i].attack;
				//敵にダメージを与える
				characters[characters[i].target].hp -= damage;
				//敵のHPが負の値になったかどうか判定する
				if (characters[characters[i].target].hp < 0)
				{
					//敵のHPを0にする
					characters[characters[i].target].hp = 0;
				}
				//戦闘シーンの画面を再描画する関数を呼び出す
				DrawBattleScreen();

				//敵にダメージを与えたメッセージを表示する
				printf("%sに　%dの　ダメージ！\n", characters[characters[i].target].name, damage);

				//キーボード入力を待つ
				_getch();

				break;
			}
			case COMMAND_SPELL:	//呪文
				break;
			case COMMAND_RUN:	//逃げる
				//逃げ出したメッセージを表示
				printf("%sは　にげだした！\n", characters[i].name);

				//キーボード入力を待つ
				_getch();

				//1/6の確率で逃げ出すのを失敗させる処理
				int run = rand() % 6 + 1;
				//runが1となったとき
				if (run == 1) {
					//逃げ出し失敗のメッセージを表示
					printf("しかし　にげられなかった・・・");

					//キーボード入力を待つ
					_getch();

					break;
				}
				//1以外の数値が出たとき
				else{
					//戦闘シーンの関数を抜ける（逃げ出し成功）
					return;
				}
			}

			//攻撃対象を倒したかどうかを判定する
			if (characters[characters[i].target].hp <= 0)
			{
				//攻撃対象によって分岐させる
				switch (characters[i].target)
				{
				//プレイヤーなら
				case CHARACTER_PLAYER:
					//戦闘シーンの画面を再描画する関数を呼び出す
					DrawBattleScreen();
					//ゲームオーバー
					printf("%sは　たおされた・・・\n", characters[characters[i].target].name);
					break;

				//モンスターなら
				case CHARACTER_MONSTER:
					//モンスターのアスキーアートを何も表示しないように書き換える
					strcpy_s(characters[characters[i].target].aa, "\n");
					//戦闘シーンの画面を再描画する関数を呼び出す
					DrawBattleScreen();
					//モンスターを倒したメッセージを表示する
					printf("%sを　たおした！\n", characters[characters[i].target].name);

					break;
				}

				//キーボード入力を待つ
				_getch();

				//戦闘シーンの関数を抜ける
				return;
			}
		}
	}
}


//プログラムの実行開始を宣言
int main() {
	//乱数をシャッフルする
	srand((unsigned int)time(NULL));
	//ゲームを初期化する変数を呼び出す
	Init();
	//戦闘シーンの関数を呼び出す
	Battle(MONSTER_SMILE);
}


