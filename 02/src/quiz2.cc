/*
ex02.cc
概要：EOFまでの入力回数を出力するプログラム
Author: Issei Ichikawa
Date: 2023-10-05
*/

#include <iostream>

using namespace std;

int main() {
    int count;
    string s;
    while(cin >> s) {
        count++;
    }
    cout << count << endl;
}