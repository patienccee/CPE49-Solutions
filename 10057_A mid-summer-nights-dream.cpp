//$\sum |X_i - A| 的值最小，A 必須是這組數字的中位數
/*
題目要求輸出的三個數字：
    最小的可能 A：中位數。
    輸入中有多少個數字符合 A 的性質：計算輸入中等於「左中間」或「右中間」數字的總個數。
    共有多少種整數 A 可選：(右中間數 - 左中間數 + 1)。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    // 題目說 N 可能很大，加速輸入
    ios::sync_with_stdio(0); cin.tie(0);

    while (cin >> N) { 
        vector<int> numbers(N); // 儲存輸入的數字
        for (int i = 0; i < N; i++) cin >> numbers[i]; 
        
        sort(numbers.begin(), numbers.end()); // 排序以找到中位數
        
        int m1 = numbers[(N - 1) / 2]; // 左中位數
        int m2 = numbers[N / 2];       // 右中位數
        
        int countA = 0;
        for (int i = 0; i < N; i++) {
            // 只要數字等於左中位數或右中位數，都符合 A 的性質
            if (numbers[i] == m1 || numbers[i] == m2) {
                countA++;
            }
        }
        
        int rangeA = m2 - m1 + 1;
        
        cout << m1 << " " << countA << " " << rangeA << endl;
    }
    return 0;
}