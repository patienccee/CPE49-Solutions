#include <bits/stdc++.h> // 包含所有標準函式庫
using namespace std; 

int GCD(int a, int b) 
{ 
    // 以輾轉相除法實現最大公因數：若 b 為 0，答案是 a，否則遞迴計算
    return b == 0 ? a : GCD(b, a % b); 
} 

int main() 
{
    int T, cases = 1; // T 為測資筆數，cases 用來印 Pair 編號
    cin >> T; // 讀入測資筆數

    while (T--) // 逐筆處理每組測資
    { 
        int n1 = 0, n2 = 0; // 用來儲存十進位整數
        string a, b; // 儲存輸入的兩個二進位字串
        cin >> a >> b; 

        //二進位轉十進位
        for (int i = 0; i < a.size(); i++)
            n1 = n1 * 2 + (a[i] - '0'); 
            //把目前的數字往左挪一格，然後把新數字塞進來，例如：n1 = 5 (二進位為 101)，a[i] = '1'，則 n1 = 5 * 2 + 1 = 11 (二進位為 1011)
            //用10進位舉例:如果我有數字 12，我要加一位 3 變成 123， 12 * 10 + 3 = 123

        for (int i = 0; i < b.size(); i++)
            n2 = n2 * 2 + (b[i] - '0'); 
        
        if (GCD(n1, n2) != 1) // 最大公因數不為 1，有共同的質因數，則輸出 "All you need is love!"
            cout << "Pair #" << cases++ << ": All you need is love!\n";
        else
            cout << "Pair #" << cases++ << ": Love is not all you need!\n";
    }

    return 0; 
}