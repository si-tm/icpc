#include <iostream>
#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

// g++ b.cpp -o b.out
// ./b.out <input> output
// ダウンロードする！
// cp ../../../Downloads/b2 . 
// ./b.out <b2> b2_out

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<ll> a(n), b(n);
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        for(int i = 0;i < n;i++){
            cin >> b[i];
        }
        for(int i = 1;i < n;i++){
            a[i] = a[i] + a[i - 1];
        }
        for(int i = 1;i < n;i++){
            b[i] = b[i] + b[i - 1];
        }

        // 確認
        // for(int i = 0;i < n;i++){
        //     cout << a[i] << " ";
        // }
        // cout << endl;
        // for(int i = 0;i < n;i++){
        //     cout << b[i] << " ";
        // }
        // cout << endl;
      

        // 勝ってる順番を書く
        string ans_s;
        for(int i = 0;i < n;i++){
            if(a[i] > b[i]){
                ans_s += 'a';
            }
            else if(a[i] < b[i]){
                ans_s += 'b';
            }
            // else if(ans_s.size() > 1 && a[i] == b[i]){
            //     // cout << ans_s.size() << " " << i << endl;
            //     ans_s += ans_s[ans_s.size() -1];
            // }
        }

        ll ans = 0;
        for(int i = 1;i < ans_s.size();i++){
            if(ans_s[i] != ans_s[i - 1]) ans++;
        }

        // cout << ans_s << endl;
        cout << ans << endl;
      
    }
}