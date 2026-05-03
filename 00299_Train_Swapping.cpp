//計算將一個亂序數組排列成升序（1, 2, 3...）時，「交換相鄰元素」的最少次數。

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 雖然這題資料量小，但加上去是好習慣
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // 加速輸入輸出

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int L;
        cin >> L;
        
        // 使用 vector 或較大的陣列更安全
        vector<int> A(L);
        for (int i = 0; i < L; i++) { // 讀取每個元素
            cin >> A[i];
        }

        int cnt = 0;
        // 逆序數對計算邏輯 (你的邏輯很棒！)
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < i; j++) {
                if (A[j] > A[i]) { // 如果前面的比後面的大
                    cnt++;
                }
            }
        }

        // 嚴格按照題目要求的格式輸出
        cout << "Optimal train swapping takes " << cnt << " swaps.\n";
    }

    return 0;
}