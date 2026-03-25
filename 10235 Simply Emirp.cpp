#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) // 只需檢查到 sqrt(x)，因為如果 x 有大於 sqrt(x) 的因數，必定有一個小於 sqrt(x) 的對應因數
    {
        if (x % i == 0) return false;
    }
    return true;
}
 
// 反轉數字的函式
int reverseNumber(int x)
{
    int rev = 0;
    while (x > 0)
    {
        rev = rev * 10 + x % 10; // 將 x 的最後一位數字加到 rev 的末尾
        x /= 10;
    }
    return rev;
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (!isPrime(n))
        {
            cout << n << " is not prime.\n";
            continue;
        }

        int rev = reverseNumber(n);

        if (rev != n && isPrime(rev))
        {
            cout << n << " is emirp.\n";
        }
        else
        {
            cout << n << " is prime.\n";
        }
    }
    return 0;
}