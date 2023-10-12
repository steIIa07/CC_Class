/*
quiz.cpp
概要：<?>*</?>を格納した文字列から、タグと要素を分けてリストに格納する
Author: Issei Ichikawa
Date: 2023-10-11
*/
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct Tag {
  string tag;
  string element;
};

string::iterator disassembly(string::iterator start, string::iterator end, list<Tag>& words) {
    Tag word;

    string::iterator tag_start = find(start, end, '<'); // <の位置
    string::iterator tag_end = find(tag_start, end, '>'); // >の位置

    word.tag = string(tag_start + 1, tag_end); // タグの抽出
    string end_tag = "</" + word.tag + ">"; // </tag>の文字列を作成

    string::iterator element_start = tag_end + 1; // 要素の開始位置
    string::iterator element_end = search(element_start, end, end_tag.begin(), end_tag.end()); // </の位置

    word.element = string(element_start, element_end); // 要素の抽出
    words.push_back(word);

    return element_end + end_tag.size(); // 探索開始位置を更新
}

int main() {
    string xml = "<noun>I</noun> <verb>talk</verb> <adverb>about</adverb> <noun>running</noun>";
    list<Tag> words;
    
    string::iterator search_start = xml.begin(); // 探索開始位置
    string::iterator search_end = xml.end(); // 探索終了位置

    while(find(search_start, search_end, '<') != search_end) { // 探索範囲に<がある間
        search_start = disassembly(search_start, search_end, words); // 要素を分解してリストに格納
    }

    // 確認用の出力
    // for(auto itr = words.begin(); itr != words.end(); ++itr){
    //     cout << itr->tag << " " << itr->element << endl;
    // }

    return 0;
}
