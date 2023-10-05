/*
ex02.cc
概要：EOFまでの入力回数を出力するプログラム
Author: Issei Ichikawa
Date: 2023-10-05
*/

#include <iostream>

int main() {
    int count;
    std::string s;
    while(std::cin >> s) {
        count++;
    }
    std::cout << count << std::endl;
}