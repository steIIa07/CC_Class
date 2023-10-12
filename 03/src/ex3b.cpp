/*
ex3b.cpp
概要：課題3b T行のc, iを入力し、cとiの値に応じてvector配列を操作するプログラム
Author: Issei Ichikawa
Date: 2023-10-05
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T; // T回の操作をする
    vector<int> X;

    X.clear();

    cin >> T;

    for(int j = 0; j < T; ++j) {
        char c; // 操作の種類
        int i; // 操作対象のインデックス

        cin >> c >> i;
        
        if(c == 'a') { // 追加
            int num; // 追加する値
            cin >> num;
            X.insert(X.begin() + i, num);
        }
        else if(c == 'd') { // 削除
            X.erase(X.begin() + i);
        }
        else if(c == 'p') { // 出力
            cout << X[i] << endl;
        }
    }

    return 0;
}
