// ConsoleApplication.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "../include/lib_func.h"

int main()
{
	list lst;
	initialize_list(&lst);

	node n[1000];
	for (int i = 0; i < 1000; i++) {
		initialize_node(n + i, i);// 要素に追加順の番号を入れる
		push_front(&lst, n + i);
	}

	printf("Count down!\n");

	// 新しく追加したものが前に来るので、大きな数の順に取り出される
	node* p = lst.header;
	while (p) {
		printf("%d\n", p->data);
		p = get_next(p);
	}

	//キーボードを1回うったらプロセスの終了
	std::cout << "PRESS KEY!\n";
	getchar();
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー
