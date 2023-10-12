/*
quiz.cpp
概要：連想記憶phonebooに指定されたデータを格納し、出力するプログラム
Author: Issei Ichikawa
Date: 2023-10-12
*/

#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, string> phonebook; // 連想記憶phonebookの宣言

    // phonebookにデータを格納
    phonebook["John"] = "555-0000";
    phonebook["Paul"] = "555-1111";
    phonebook["Ringo"] = "555-2222";
    phonebook["George"] = "555-3333";

    // phonebookのデータを出力
    for(auto p : phonebook) {
        cout << p.first << "'s number: " << p.second << endl;
    }

    return 0;
}