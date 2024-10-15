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

    while(true) {
        int n;
        cin >> n;
        if(n == 0) break;

        vector<int> c(n);
        for (int i=0; i<n; i++) {
            cin >> c[i];
        }
        if (c[0]!=c[n-1]) {
            cout << "No" << endl;
            continue;
        }

        vector<vector<int>> vec(n, vector<int>(n,0));
        for(int i=0; i<n; i++) {
            // south
            vec[n-1][i] = c[i];
        }
        for(int i=0; i<n; i++) {
            //east
            vec[n-i-1][n-1] = c[i];
        }
        for(int i=0; i<n; i++) {
            // north
            vec[0][n-i-1] = c[i];
        }
        for(int i=0; i<n; i++) {
            //west
            vec[i][0] = c[i];
        }

        cout << "Yes" << endl;
        for (int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout << vec[i][j] << " ";
            }
            cout << endl;
        }

    }
}