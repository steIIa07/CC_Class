/*
ex02.cc
概要：課題2 学籍番号，名前，苗字を読み込み，指定された表形式で出力するプログラム
Author: Issei Ichikawa
Date: 2023-10-05
*/

#include <iostream>

using namespace std;

int main() {
    // 必要な変数の宣言
    string first_name, last_name, student_id;
    int count = 0;

    // 以下、リストの出力
    cout << "+==============+==============+==========+" << endl;
    while(cin >> student_id >> first_name >> last_name) {
        // 各列を｜で区切りつつ、整形した文字列を作成
        string space_last(12 - last_name.size(), ' ');
        string space_first(12 - first_name.size(), ' ');
        string space_id(8 - student_id.size(), ' ');
        const string out = "| " + last_name + space_last + " | " + first_name + space_first + " | " + student_id + space_id + " |";
        
        // 出力
        cout << out << endl;

        // 5行ごとに区切りを入れる
        if(++count % 5 == 0)
            cout << "+--------------+--------------+----------+"<< count << endl;
    }
    cout << "+==============+==============+==========+" << endl;

    return 0;
}