/*
quiz.cpp
概要：入力した文字列をlistに保存し、逆順にソートして出力する
Author: Issei Ichikawa
Date: 2023-10-11
*/

#include <iostream>
#include <list>

using namespace std;

bool compare(string a, string b) {
    if(a < b) {
        return false;
    } else {
        return true;
    }
}

int main() {
    // 変数の宣言
    list<string> IDs;
    string ID;

    // 入力
    while (cin >> ID) {
        IDs.push_back(ID);
    }

    // ソート
    IDs.sort(compare);

    // 出力
    for(auto it = IDs.begin(); it != IDs.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}