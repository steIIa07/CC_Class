/*
ex02.cc
概要：課題2 学籍番号，名前，苗字を読み込み，指定された表形式で出力するプログラム
Author: Issei Ichikawa
Date: 2023-10-05
*/

#include <iostream>

using namespace std;

void print_space(int count) {
    while(count-- > 0) {
        cout << " ";
    }
}

int main() {
    // 必要な変数の定義
    string first_name, last_name, student_id;
    int count = 0;

    // 以下、リストの出力
    cout << "+==============+==============+==========+" << endl;
    while(cin >> student_id >> last_name >> first_name) {
        // 各列を｜で区切りつつ、整形して出力
        cout << "| " << first_name;
        print_space(12 - first_name.size());
        cout << " | " << last_name; 

        print_space(12 - last_name.size());
        cout << " | " << student_id;

        print_space(8 - student_id.size());
        cout << " |" << endl;

        // 5行ごとに区切りを入れる
        if(++count % 5 == 0)
            cout << "+-============-+-============-+-========-+" << count << endl;
    }
    cout << "+==============+==============+==========+" << endl;

    return 0;
}