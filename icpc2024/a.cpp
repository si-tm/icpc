#include <iostream>
#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

// g++ a.cpp -o a.out
// ./a.out <input> output
// cp ../../../Downloads/a1 . 
// ./a.out <a1> a1_out

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        ll tmp = 300, ans = 0;
        for(int i = 0;i < n;i++){
            ll x;
            cin >> x;
            if(x <= tmp){
                ans += x;
                tmp -= x;
            }
        }
        cout << ans << endl;
    }
}