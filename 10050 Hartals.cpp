#include <bits/stdc++.h>
using namespace std;
int main() {
    int T, D, P;
    cin>>T;
    while(T--) {
        cin>>D; //day
        cin>>P; //political party
        int h[105]; //各政黨罷會間隔天數
        //input
        for(int i=0; i<P; i++) cin>>h[i]; //h[i] = 第 i 個政黨的幾天一次

        //check
        int table[3655]={0}; //calendar
        for(int i=0; i<P; i++) {  //從第一個政黨開始逐一處理
            for(int j=h[i]; j<=D; j+=h[i]) { //從第一個罷會日開始，依照間隔天數往後推算 
                if(j%7!=6 && j%7!=0) //遇到每週六或七不計
                    table[j]=1; //標記罷會日
            }
        }

        //output
        int cnt=0;
        for(int i=1; i<=D; i++) {
            if(table[i]==1)
                cnt++; //統計罷會日數量
        }
        cout<<cnt<<"\n";
    }
    return 0;
}