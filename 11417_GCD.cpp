#include <iostream>
using namespace std;

// 1. GCD 函式
int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

int main() {
    int N;
    // 2. 處理多組輸入，直到 N=0 為止
    while (cin >> N && N != 0) {
        long long G = 0;
        
        // 3. 按照題目給的公式進行加總
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j <= N; j++) {
                G += GCD(i, j);
            }
        }
        cout << G << endl;
    }
    return 0;
}