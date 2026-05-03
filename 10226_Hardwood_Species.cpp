/*統計大量字串出現的頻率並依字典順序排序，計算百分比，輸出小數點後四位
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    // 加速輸入輸出，這在處理 1,000,000 筆資料時很重要
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0; // 讀取 T，如果失敗（例如 EOF），就結束程式
    
    string s;
    cin.ignore(); // 跳過 T 之後的換行
    getline(cin, s); // 跳過題目說的那個空白行

    while (T--) {
        map<string, int> tree; // 改用 int 存次數，比較直覺
        int total = 0; // 總樹的數量

        // 讀取每棵樹的名字，直到遇到空白行或結束
        while (getline(cin, s) && s != "") {
            tree[s]++; // 如果 s 已經在 map 中，則次數加 1；如果沒有，則會自動插入 s 並初始化為 0，然後再加 1   
            total++; // 每讀到一棵樹，總數就加 1
        }

        // 輸出結果
        // [name, count] 是 C++17 的新寫法，直接把 map 的內容拆開
        for (auto const& [name, count] : tree) {      // 遍歷 map 中的每個元素，name 是樹的名字，count 是該樹的數量
            double percent = (double)count / total * 100.0; // 計算該樹的百分比，先把 count 轉成 double，然後除以 total，再乘以 100
            cout << name << " " << fixed << setprecision(4) << percent << "\n"; // 輸出樹的名字和百分比，fixed 是固定小數點格式，setprecision(4) 是保留 4 位小數
        }

        // 題目要求：兩組測資之間要有空行，但最後一組後面不用
        if (T > 0) cout << "\n";
    }

    return 0;
}