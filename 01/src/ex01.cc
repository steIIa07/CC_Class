/*
ex01.cc
概要：課題１ ファーストネーム、ミドルネーム、ラストネームを入力し、
     それらを整形して表示するプログラム
Author: Issei Ichikawa
Date: 2023-10-05
*/

#include <iostream>

using namespace std;

int main() {
    // ファーストネーム、ミドルネーム、ラストネームを入力
    string first_name, middle_name, last_name;
    cout << "Please input your first name" << endl;
    cin >> first_name;
    cout << "Please input your middle name" << endl;
    cin >> middle_name;
    cout << "Please input your last name" << endl;
    cin >> last_name;

    // フレームの作成
    const string frame_line(first_name.size() + middle_name.size() + last_name.size() + 14, '*');
    string space(first_name.size() + middle_name.size() + last_name.size() + 10, ' ');
    space = "* " + space + " *";
    const string out = "* Hello, " + first_name + " " + middle_name + " " + last_name + "! *";

    // 最終的な出力
    cout << frame_line << endl;
    cout << space << endl;
    cout << out << endl;
    cout << space << endl;
    cout << frame_line << endl;

    return 0;
}

// 動作確認

// 5. 名前が極端に長い場合
// 文が長いため、表示に問題はあるが、正しく表示される

// 6. 名前が文字が英語以外のとき、３つの言語で実行
// 6.1. 日本語 正しく表示される                     *
// * Hello, 伊知川 - 壱星! *

// 6.2 韓国語 ？になってしまう
// * Hello, ? - ??! *

// 6.3 ロシア語
// 表示されない
// Иванов - Иван を入力 -> * Hello,  - ! *

// 日本語・英語は正しく表示されるが、それ以外は正しく表示されない
