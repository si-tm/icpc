#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

// k日目までの合計
ll f(ll k){
    return k*k;
}

// 休日
ll sum_n(ll n, ll d){
    if(n <= d) return n;
    ll ans = 0;
    ans += f(n/d)*d;
    ans += ((n/d + 1)*2 - 1)*(n%d);
    return ans;
}

//　練習日
ll sum_m(ll m, ll d){
    if(m <= d) return m;
    ll ans = 0;
    ans += f(m - d + 1);
    ans += d - 1;
    return ans;
}

int main()
{
    while(1){
        ll n, m;
        cin >> m >> n; //逆
        if(n == 0 && m == 0) return 0;
        /*
        n と m はそれぞれ練習日と休息日の日数
        m : 分割したくない
        n : 分割したい
        m, n, m, n, m
        になる予感
        */

       //どちらかが0の時
       if(n == 0 || m == 0){
        cout << f(m) - f(n) << endl;
        continue;
       }
       //分割できない時
       if(n == 1){
        cout << f(m) - f(n) << endl;
        continue;
       }
       if(m == 1){
        cout << f(m) - sum_n(n, 2) << endl;
        continue;
       }
       //分割できる時
       ll d_m = 1, d_n = 2;
       ll pre = sum_m(m, d_m) - sum_n(n, d_n);
       if(!(d_m <= m && d_n <= n)) cout << pre << endl;
       ll max_v = pre;
       while(d_m <= m && d_n <= n){
        d_m++;
        d_n++;
        if(d_m > m || d_n > n){
            cout << max_v << endl;
            break;
        }
        ll tmp = sum_m(m, d_m) - sum_n(n, d_n);
        max_v = max(max_v, tmp);
       }
    }
    return 0;
}
