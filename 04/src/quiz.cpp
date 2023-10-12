/*
quiz.cpp
概要：３つの関数で実数値列を読み込み、中間値を算出・出力するプログラム
Author: Issei Ichikawa
Date: 2023-10-10
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

istream& read(istream& is, vector<double>& v) {
    double inputValue = 0; // 入力値を格納する変数

    while(is >> inputValue) { // 空になるまで入力を続ける
        v.push_back(inputValue);
    }
    return is; // 入力ストリームを返す
}

double median(vector<double> v) {
    auto size = v.size();
    
    if(size == 0) { // 空の場合
        return -1;
    }

    // 空でないとき、中間値を返す
    sort(v.begin(), v.end());
    int mid = size / 2;
    return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

int main() {
    // vectorの宣言と初期化
    vector<double> v;
    v.clear();

    read(cin, v);
    const double medianValue = median(v);

    //　出力(入力値の順番は変わらない) 
    cout << "input: ";
    for(auto i : v) {
        cout << i << " ";
    }
    cout << endl;
    cout << "median: " << medianValue << endl;
}