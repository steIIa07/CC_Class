/*
ex06a.cpp
概要：課題6b 6aからlist->vectorに変更、それ以外は同じで、同じ結果が得られることを確認する
Author: Issei Ichikawa
Date: 2023-10-12
*/

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() {
   list<string> words;
   string word1, word2; // 文字列
   auto itr = words.begin(); // イテレータ
   char command; // コマンド
   
    while(cin >> command) { // コマンドの読み込み
        switch(command) {
            case 'a': // a の場合 listの末尾に文字列を追加
                cin >> word1;
                words.push_back(word1);
                break;

            case 'd': // d の場合 listの中から文字列を削除
                cin >> word1;
                words.erase(remove(words.begin(), words.end(), word1), words.end());
                break;

            case 'i': // i の場合 listの中の文字列の前に文字列を挿入
                cin >> word1 >> word2;
                itr = words.begin();
                while(itr != words.end()) {
                    if(*itr == word1) {
                        words.insert(itr, word2);
                        if(*itr != word1) itr++;
                    }
                    if(itr != words.end()) itr++;
                }
                break;

            case 'r': // r の場合 listの中の文字列を置換
                cin >> word1 >> word2;
                replace(words.begin(), words.end(), word1, word2);
                break;

            case 'p': // p の場合 listの中の文字列を出力
                for(auto itr = words.begin(); itr != words.end(); itr++) {
                    cout << *itr << " ";
                }
                cout << endl;
                break;
        }
    }

    return 0;
}