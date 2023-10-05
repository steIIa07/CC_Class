/*
ex3a.cpp
概要：課題3a N個の整数X_iを読み込み，T個の各区間[Lj, Rj）での和を計算するプログラム
Author: Issei Ichikawa
Date: 2023-10-05
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int numOfTimes; // N, Tに相当
    vector<int> X;

    cin >> numOfTimes; // Nを読み込み

    // N個の整数X_iを読み込み、vector Xに格納
    for(int i = 0; i < numOfTimes; i++){
        int tmp;
        cin >> tmp;
        X.push_back(tmp);
    }

    cin >> numOfTimes; // Tを読み込み

    // T個の各区間[Lj, Rj)について
    for(int i = 0; i < numOfTimes; i++){
        int L, R;
        cin >> L >> R;
        int sum = 0;
        for(int j = L; j < R; j++){
            sum += X[j]; // 区間(L, R]の和を計算
        }
        cout << sum << endl; // 和を出力
    }

    return 0;
}

