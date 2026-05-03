/*
餘數優先：餘數（n % M）較小的排在前面。

餘數相同時（Tie）：

    一奇一偶：奇數排在偶數前面。

    兩者皆奇：較大的奇數排在前面。

    兩者皆偶：較小的偶數排在前面。
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;

bool cmp(int a, int b) {
    int modA = a % m;
    int modB = b % m;

    // 1. 如果餘數不同，小的排前面
    if (modA != modB) return modA < modB;

    // 餘數相同的情況下：
    bool aIsOdd = abs(a % 2) == 1;
    bool bIsOdd = abs(b % 2) == 1;

    // 2. 一奇一偶：奇數排前面
    if (aIsOdd != bIsOdd) return aIsOdd; // 如果 a 是奇數則回傳 true

    // 3. 兩者皆為奇數：大的排前面
    if (aIsOdd && bIsOdd) return a > b;

    // 4. 兩者皆為偶數：小的排前面
    return a < b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m && (n != 0 || m != 0)) {
        cout << n << " " << m << "\n";
        
        vector<int> A(n); // 使用 vector 更有彈性
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        sort(A.begin(), A.end(), cmp);

        for (int i = 0; i < n; i++) {
            cout << A[i] << "\n";
        }
    }
    // 依照題目要求，最後還要印出一組 0 0
    cout << "0 0\n";
    
    return 0;
}