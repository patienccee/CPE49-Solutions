/*
統計頻率：讀取一整行字串，算出每個 ASCII 字元出現了幾次。
排序規則：
規則 A：出現次數越少的排越前面（頻率升序）。
規則 B：如果次數一樣，ASCII 碼較大 的排在前面（ASCII 降序）。
輸出格式：每組測資之間要有一個空行（最後一組後面不要有空行）。
*/

#include <bits/stdc++.h> // 包含所有標頭檔
using namespace std;
int main()
{
    string s;
    int flag=0; // 用來控制是否輸出空行，第一次輸出後設為 1，之後每次輸出前都檢查 flag 是否為 1，如果是就輸出空行。
    
    while(getline(cin,s))      // 讀取一整行字串
    {
        int table[256]={0}; // ASCII 字元的頻率表，初始化為 0
        for(int i=0;i<s.length();i++){ // 統計每個字元的頻率
            table[s[i]]++;} // s[i] 是字串 s 中的第 i 個字元，table[s[i]] 是該字元的頻率，對其加 1
        
        if(flag) cout<<"\n";
        //頻率由小而大排列，遇到相同頻率者，ASCII大者靠前
        for(int i=1;i<=s.length();i++)
        {
            for(int j=127;j>=32;j--) // ASCII 字元的範圍是 32 到 127
            {
                if(table[j]==i) // 如果字元 j 的頻率等於 i，則輸出該字元和頻率
                    cout<<j<<" "<<i<<"\n";
            }
        }
        flag=1;
    }
    return 0;
}