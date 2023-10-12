/*
ex07.cpp
概要：課題7 
Author: Issei Ichikawa
Date: 2023-10-12
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// 空白文字かどうかを判定する
bool space(char c) {
    return isspace(c);
}

// 空白文字でないかどうかを判定する
bool not_space(char c) {
    return !isspace(c);
}

// 文字列を単語に分割する
vector<string> split(string str) {
    vector<string> result;
    string::iterator i = str.begin(), j;

    result.clear();

    i = find_if(i, str.end(), not_space); // 最初の単語の先頭を探す
    j = find_if(i, str.end(), space); // 最初の単語の末尾を探す

    while(i != str.end()) {
        if(i != j) result.push_back(string(i, j)); // 単語を格納する
        i = find_if(j, str.end(), not_space); // 次の単語の先頭を探す
        j = find_if(i, str.end(), space); // 次の単語の末尾を探す
    }

    return result;
}

// 単語の出現行を記録する
void record(vector<string>& words, map<string, vector<int>>& map, int line) {
    for(auto word : words) {
        if(map.find(word) == map.end()) {
            map[word] = vector<int>();
        }
        map[word].push_back(line);
    }
}

// 単語の出現行を出力する
void print(string word, map<string, vector<int>>& map) {
    if(map.find(word) == map.end()) { // 単語が存在しない場合
        cout << -1 << endl;
    } else {
        for(auto i : map[word]) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    int lines; // N と M の値を格納
    map<string, vector<int>> map; // 単語と行番号を格納する連想配列
    vector <string> words; // 単語を格納する配列
    string statement, word;

    cin >> lines;
    cin.ignore(); // cin の後の改行読み飛ばし

    // 単語の記録
    for(auto i = 1; i <= lines; i++) {
        getline(cin, statement);
        words = split(statement);
        record(words, map, i);
    }

    // クエリ
    cin >> lines;
    for(auto i = 0; i < lines; i++) {
        cin >> word;
        print(word, map);
    }

    return 0;
}