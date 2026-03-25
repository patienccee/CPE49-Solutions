#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a;
    while (cin >> n >> a)
    {
        if (n < 2 || a < 2)
        {
            cout << "Boring!\n";
            continue;
        }

        bool ok = true;
        long long temp = n; // 用來檢查是否能一路整除到 1 的暫存變數

        // 先檢查是否能一路整除到 1。
        while (temp > 1)
        {
            if (temp % a != 0) //
            {
                ok = false;
                break;
            }
            temp /= a;
        }

        if (!ok)
        {
            cout << "Boring!\n";
        }
        else
        {
            cout << n;
            while (n > 1)
            {
                n /= a;
                cout << ' ' << n;
            }
            cout << '\n';
        }
    }
    return 0;
}