#include <iostream>
#include <bits/stdc++.h> 
// #include <atcoder/all>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
// using namespace atcoder;
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

// g++ d.cpp -o d.out
// ./d.out <input> output
// cp ../../../Downloads/d1 . 
// ./d.out <d1> d1_out

ll min_l(ll x, ll y){
    if(x > y) return y;
    return x;
}
ll abs_l(ll x){
    if(x > 0) return x;
    return x*(-1);
}

ll lb(vector<ll> x, ll tmp){
    // tmpより大きい最小のxの要素

    ll lo = 0;
    ll hi = x.size()-1;
    if (x[hi] <= tmp) return -1;
    while(lo<hi-1) {
        ll mid = (hi+lo)/2;
        if (tmp < x[mid]) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return hi;
}

ll ub(vector<ll> x, ll tmp){
    // tmpより小さい最大のxの要素


    ll lo = 0;
    ll hi = x.size()-1;
    if(x.size() == 1 && tmp < x[0]) return 0;
    if(x.size() == 1 && tmp >= x[0]) return -1;
    if (x[lo] >= tmp) return -1;
    while(lo<hi-1) {
    // while(lo<hi) {
        ll mid = (hi+lo)/2;
        if (tmp <= x[mid]) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    }
    return lo;
}

// int main(){
//     vector<ll> x = {1, 2, 4, 5, 10};
//     ll tmp = 4;
//     // cout << ub(x, tmp) << endl;
//     cout << x[ub(x, tmp)] << endl;
// }


int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        ll a, b, d;
        cin >> a >> b >> d;
        map<ll, vector<ll>> mx, my; // mx[x] = {y1, y2, ...}
        vector<ll> xv,yv;
        for(int i = 0;i < n;i++){
            // 障害物
            ll x, y;
            cin >> x >> y;
            xv.push_back(x);
            yv.push_back(y);
            if(mx.count(x) == 0){
                vector<ll> tmp;
                mx[x] = tmp;
                mx[x].push_back(y);
            }
            if(my.count(y) == 0){
                vector<ll> tmp;
                my[y] = tmp;
                my[y].push_back(x);
            }
        }

        for(int i = 0; i < xv.size();i++){
            int x = xv[i];
            sort(mx[x].begin(), mx[x].end());
        }
        for(int i = 0; i < yv.size();i++){
            int y = yv[i];
            sort(my[y].begin(), my[y].end());
        }

        // 方向
        vector<pair<ll, ll>> dir(4);
        dir[0] = pair(1, 0);
        dir[1] = pair(0, 1);
        dir[2] = pair(-1, 0);
        dir[3] = pair(0, -1);
        ll tmp_dir = 0; 

        //位置
        pair<ll, ll> tmp_xy;
        tmp_xy.first = a;
        tmp_xy.second = b;

        ll shogai_index, idou;

        map<pair<ll, ll>, ll> kioku;

        while(d > 0){
            // cout << tmp_xy.first << " " << tmp_xy.second << " dir " << tmp_dir << endl;
            if(kioku.count(tmp_xy) != 0){
                ll loop_d = d - kioku[tmp_xy];
                d = d%loop_d;
            }
            else{
                kioku[tmp_xy] = d;
            }

            // cout << "途中 : " << tmp_xy.first << " " << tmp_xy.second << endl;
            // cout << "d : " << d << endl;
            // cout << "tmp_dir : " << tmp_dir << endl;
            // 進方向に障害物がない場合、残りの長さを足す
            switch(tmp_dir){
                case 0: // 東
                    // my[tmp_xy.second]の中でtmp_xy.secondより大きく一番小さいxを調べる
                     if(my.count(tmp_xy.second) == 0){
                        shogai_index = -1;
                    }
                    else{
                        // shogai_index = ub(my[tmp_xy.second], tmp_xy.second);
                        shogai_index = lb(my[tmp_xy.second], tmp_xy.second);
                    }

                    if(shogai_index == -1){
                        // 障害がなければdir[tmp_dir]の方向に残りのdをプラスする
                        tmp_xy.first += d*dir[tmp_dir].first;
                        tmp_xy.second += d*dir[tmp_dir].second;
                        d = 0;
                    }
                    else{
                        // 障害があればdir[tmp_dir]の方向にmin(残りのd, my[tmp_xy.second][shogai_index] - my[tmp_xy.second]) - 1をプラスする + 方向転換する
                        // cout << "idou min : " <<  abs_l(my[tmp_xy.second][shogai_index] - tmp_xy.first) - 1 << endl;
                        idou = min_l(d, abs_l(my[tmp_xy.second][shogai_index] - tmp_xy.first) - 1);
                        // cout << "idou : " <<  idou << endl;
                        tmp_xy.first += idou*dir[tmp_dir].first;
                        tmp_xy.second += idou*dir[tmp_dir].second;
                        d -= idou;
                        // 進行方向に障害物がある場合
                        tmp_dir = (tmp_dir+1)%4;
                    }
                    break;
                case 1: // 北
                    if(my.count(tmp_xy.second) == 0){
                        shogai_index = -1;
                    }
                    else{
                        // shogai_index = ub(my[tmp_xy.second], tmp_xy.second);
                        // shogai_index = lb(my[tmp_xy.second], tmp_xy.second);
                        shogai_index = lb(mx[tmp_xy.first], tmp_xy.second);
                        // cout << "shogai "  << shogai_index << endl;
                    }
                    // mx[tmp_xy.first]の中でtmp_xy.firstより大きく一番小さいyを調べる
                    // shogai_index = lb(mx[tmp_xy.first], tmp_xy.first);

                    if(shogai_index == -1){
                        // 障害がなければdir[tmp_dir]の方向に残りのdをプラスする
                        tmp_xy.first += d*dir[tmp_dir].first;
                        tmp_xy.second += d*dir[tmp_dir].second;
                        d = 0;
                    }
                    else{
                        // 障害があればdir[tmp_dir]の方向にmin(残りのd, my[tmp_xy.second][shogai_index] - my[tmp_xy.second])をプラスする + 方向転換する
                        idou = min_l(d, abs_l(mx[tmp_xy.first][shogai_index] - tmp_xy.second) - 1);
                        // cout << "idou " << idou << "d " << d << "障害の場所 " << mx[tmp_xy.first][shogai_index] << endl;
                        tmp_xy.first += idou*dir[tmp_dir].first;
                        tmp_xy.second += idou*dir[tmp_dir].second;
                        d -= idou;
                        // 進行方向に障害物がある場合
                        tmp_dir = (tmp_dir+1)%4;
                        // cout << tmp_dir << endl;
                    }

                break;
                case 2: // 西
                    // my[tmp_xy.second]の中でtmp_xy.secondより小さく一番大きいxを調べる
                    // cout << my[tmp_xy.second] <<  " " << tmp_xy.second << endl;
                    if(my.count(tmp_xy.second) == 0){
                        shogai_index = -1;
                    }
                    else{
                        shogai_index = ub(my[tmp_xy.second], tmp_xy.second);
                    }
                    if(shogai_index == -1){
                        // 障害がなければdir[tmp_dir]の方向に残りのdをプラスする
                        tmp_xy.first += d*dir[tmp_dir].first;
                        tmp_xy.second += d*dir[tmp_dir].second;
                        d = 0;
                    }
                    else{
                        // 障害があればdir[tmp_dir]の方向にmin(残りのd, my[tmp_xy.second][shogai_index] - my[tmp_xy.second])をプラスする + 方向転換する
                        idou = min_l(d, abs_l(my[tmp_xy.second][shogai_index] - tmp_xy.first) - 1);
                        tmp_xy.first += idou*dir[tmp_dir].first;
                        tmp_xy.second += idou*dir[tmp_dir].second;
                        d -= idou;
                        // 進行方向に障害物がある場合
                        tmp_dir = (tmp_dir+1)%4;
                    }

                break;
                case 3: // 南
                    // mx[tmp_xy.first]の中でtmp_xy.firstより小さく一番大きいyを調べる
                    if(my.count(tmp_xy.first) == 0){
                        shogai_index = -1;
                    }
                    else{
                    shogai_index = ub(mx[tmp_xy.first], tmp_xy.first);
                    }

                    if(shogai_index == -1){
                        // 障害がなければdir[tmp_dir]の方向に残りのdをプラスする
                        tmp_xy.first += d*dir[tmp_dir].first;
                        tmp_xy.second += d*dir[tmp_dir].second;
                        d = 0;
                    }
                    else{
                        // 障害があればdir[tmp_dir]の方向にmin(残りのd, my[tmp_xy.second][shogai_index] - my[tmp_xy.second])をプラスする + 方向転換する
                        idou = min_l(d, abs_l(mx[tmp_xy.first][shogai_index] - tmp_xy.second) - 1);
                        tmp_xy.first += idou*dir[tmp_dir].first;
                        tmp_xy.second += idou*dir[tmp_dir].second;
                        d -= idou;
                        // 進行方向に障害物がある場合
                        tmp_dir = (tmp_dir+1)%4;
                    }

                break;
            }
        }

        cout << tmp_xy.first << " " << tmp_xy.second << endl;
    }
}
