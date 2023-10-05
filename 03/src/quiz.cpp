/*
quiz.cpp
概要：標準入力から符号付整数値をEOFになるまで読み、vectorで管理し、ソートした結果を出力する
Author: Issei Ichikawa
Date: 2023-10-05
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 変数宣言
    vector<int> b;
    int input;

    // 入力 
    while(cin >> input){
        b.push_back(input);
    }
    
    // ソート
    sort(b.begin(), b.end());

    // 出力
    cout << "Sort result: ";
    for(int i = 0; i < b.size(); ++i){
        cout << b[i] << " ";
    }
    cout << endl;
}
