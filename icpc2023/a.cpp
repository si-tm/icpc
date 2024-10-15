#include <iostream>
#include <vector>
#include <limits> 
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

// g++ test.cpp -o test.out
// ./test.out < Ain > Aout

ll abs(ll x, ll y){
    if(x > y) return x - y;
    return y - x;
}

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        ll ans = -1;
        ll tmp_val = INF;
        for(int i = 0;i < n;i++){
            ll x;
            cin >> x;
            if(abs(x, 2023) < tmp_val){
                ans = x;
                tmp_val = abs(x, 2023);
            }
        }
        cout << ans << endl;
    }
}