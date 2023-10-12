/*
ex05.cpp
概要：課題5 読み込んだ文章から単語リスト(出現回数)を作成し、ソートして出力する
Author: Issei Ichikawa
Date: 2023-10-11
*/

#include <iostream>
#include <list>
#include <cctype>
#include <iomanip>

using namespace std;

struct WordCount
{
    string word;
    int count;
};

string stringProcessing(string word)
{
    string result = "";

    for(auto& c : word)
        result += tolower(c); // 小文字に変換
    
    char first = result[0]; // 先頭
    char last = result[result.size() - 1]; // 末尾

    while(first == ',' || first == '.' || first == '\'' || first == '\"' || first == '(') { // 先頭の記号を削除
        result = result.substr(1, result.size() - 1);
        first = result[0];
    }

    while(last == ',' || last == '.' || last == '\'' || last == '\"' || last == ')') { // 末尾の記号を削除
        result = result.substr(0, result.size() - 1);
        last = result[result.size() - 1];
    }
    
    return result;
}

// 単語の辞書順比較
bool compare(const WordCount& a, const WordCount& b)
{
    return a.word < b.word;
}

int main() {
    list<WordCount> word_list;
    string word;

    while(cin >> word) {
        word = stringProcessing(word);

        bool is_exist = false;
        for(auto& w : word_list) {
            if(w.word == word) { // 単語が既に存在する場合
                w.count++;
                is_exist = true;
                break;
            }
        }
        if(!is_exist) { // 単語が存在しない場合
            WordCount wc = {word, 1};
            word_list.push_back(wc);
        }
    }

    word_list.sort(compare);

    // 出力
    for(auto& w : word_list) {
        cout << left << setw(18) << w.word << " " << w.count << endl;
    }

    return 0;
}
