/*
ex04.cpp
概要：課題4 成績のリストを読み込み、成績をフォーマットに合わせて出力するプログラム
Author: Issei Ichikawa
Date: 2023-10-10
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

double median(vector<int> v) {
    auto size = v.size();
    
    if(size == 0) { // 空の場合
        return 0.0;
    }

    // 空でないとき、中間値を返す
    sort(v.begin(), v.end());
    int mid = size / 2;
    return size % 2 == 0 ? (double)(v[mid] + v[mid - 1]) / 2 : (double)v[mid];
}

int main() {
    // 必要な変数の宣言
    string first_name, last_name, student_id;
    int count = 0;
    int midterm_score, final_score;

    cout << "+==============+==============+==========+========+========+========+========+" << endl;
    while(cin >> student_id >> first_name >> last_name >> midterm_score >> final_score) { // 最初の5つの入力
        int excercise_score, sum_excercise_score = 0;
        double average_excercise_score, median_excercise_score, total_score;

        // 演習の点数を格納する配列を宣言・初期化
        vector<int> excercise_scores;
        excercise_scores.clear();

        while(cin >> excercise_score && excercise_score != -1) { // -1(終了)が入力されるまで演習の点数を入力
            excercise_scores.push_back(excercise_score);
            sum_excercise_score += excercise_score;
        }

        median_excercise_score = median(excercise_scores);
         if(excercise_scores.empty()) { // 配列が空の場合 (0で割ると例外が発生する)
            average_excercise_score = 0.0;
        } else {
            average_excercise_score = (double)sum_excercise_score / excercise_scores.size();
        }

        total_score = 0.2 * midterm_score + 0.4 * final_score + 0.4 * median_excercise_score;

        // 各列を｜で区切りつつ、整形した文字列を出力
        cout.precision(1); // 小数点以下1桁で出力
        cout << fixed; // 小数点以下を固定で出力
        cout << "| " << left << setw(12) << first_name << " | " << left << setw(12) << last_name << " | " << left << setw(8) << student_id << " | "
             << right << setw(6) << (double)sum_excercise_score << " | " << right << setw(6) << average_excercise_score << " | " 
             << right << setw(6) << median_excercise_score << " | " << right << setw(6) << total_score << " |" << endl;

        // 5行ごとに区切りを入れる
        if(++count % 5 == 0)
            cout << "+--------------+--------------+----------+---------+--------+--------+--------+" << count << endl; 
    }
    cout << "+==============+==============+==========+========+========+========+========+" << endl;

    return 0;
}
