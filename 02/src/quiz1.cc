/*
quiz1.cc
概要：1~100うち，3の倍数または3が含まれる数を出力するプログラム
Author: Issei Ichikawa
Date: 2023-10-05
*/

#include <iostream>

bool isMultipleOfThree(int n) {
    return n % 3 == 0;
}

bool isIncludeThree(int n) {
    while (n > 0) {
        if (n % 10 == 3) {
            return true;
        }
        n /= 10;
    }
    return false;
}

int main() {
    for(int i = 1; i <= 100; ++i) {
        if (isMultipleOfThree(i) || isIncludeThree(i))
            std::cout << i << std::endl;
    }
}