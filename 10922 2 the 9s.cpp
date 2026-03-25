#include <bits/stdc++.h>
using namespace std;

// 計算字串中數字的總和
int digitSum(const string& s)
{
    int sum = 0;
    for (char c : s) sum += c - '0'; // 將字元 '0' 轉換為數字 0，'1' 轉換為數字 1，以此類推
    return sum;
}

// 計算數字的總和
int digitSum(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main()
{
    string n;
    while (cin >> n && n != "0")
    {
        int sum = digitSum(n);

        if (sum % 9 != 0)
        {
            cout << n << " is not a multiple of 9.\n";
            continue;
        }
        
        // 計算 9 的 degree，直到 sum 小於或等於 9 為止
        int degree = 1;
        while (sum > 9)
        {
            sum = digitSum(sum);
            degree++;
        }

        if (sum == 9)
        {
            cout << n << " is a multiple of 9 and has 9-degree " << degree << ".\n";
        }
        else
        {
            cout << n << " is not a multiple of 9.\n";
        }
    }
    return 0;
}