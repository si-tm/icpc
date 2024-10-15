#include <iostream>
#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

// g++ c.cpp -o c.out
// ./c.out <input> output
// cp ../../../Downloads/c1 . 
// ./c.out <c1> c1_out


int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        int x,y;
        cin >> x >> y;
        if(x*y>0) {
            cout << abs(x)+abs(y) << endl;
        }
        else {
            int m = min(abs(x),abs(y));
            cout << abs(x) + abs(y) - m << endl;
        }
    }
}