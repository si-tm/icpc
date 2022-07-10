#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();

//先頭取り除く
string el_sentou(string s){
    string t = "";
    for(int i = 1;i < s.size();i++){
        t += s[i];
    }
    return t;
}


//末尾を取り除く
string el_matubi(string s){
    string t = "";
    for(int i = 0;i < s.size() - 1;i++){
        t += s[i];
    }
    return t;
}

//辞書順で取り出す
string which_jisho(string s){
    int n = s.size();
    if(n <= 1) return "";
    string x = el_matubi(s);
    string y = el_sentou(s);
    if(x < y) return x;
    return y;
}

//逆にする
string rev(string s){
    string t = "";
    for(int i = s.size() - 1;i >= 0;i--){
        t += s[i];
    }
    return t;
}


//分割
string split_s(int l, int r, string s){
    l = max(0, l);
    int n = s.size();
    r = min(n - 1, r);
    string t = "";
    if(l == r){
        t += s[l];
        return t;
    }
    for(int i = l;i <= r;i++) t += s[i];
    return t;
}

string solve(string s){

    cout << s << endl;
    
    bool is_kigo = 0;
    // ?()がなくなるまでにやる
    int n = s.size();
    int i = n - 1;
    // l : ?の位置 ,r : )の位置
    int r = 0, l = 0;
    while(i > 0){
        //)を見つける
        if(s[i] == ')'){
            is_kigo = 1;
            r = i;
            // ?(を見つける
            int j = i;
            string tmp = "";
            while(s[j] != '('){
                j--;
                if(s[j] == '(') break;
                if(s[j] == ')'){
                    i = j;
                    continue;
                }
                tmp += s[j];
            }
            l = j - 1;
            //sを戻す

            string sub_s1 = s;
            string sub_s2 = s;

            cout << split_s(0, l - 1, sub_s1) << endl;
            cout << sub_s2 << endl;
            cout << s[r + 1] << " " << n << endl;
            cout << split_s(r + 1, n, sub_s2) << endl;
            s = split_s(0, l - 1, sub_s1) + solve(rev(tmp)) + split_s(r, n - 2, sub_s2);
            i = s.size();
        }
        i--;
    }

    if(!is_kigo) return which_jisho(s);

    return s;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        //木構造...？
        string ans = solve(s);
        cout << ans << endl;
    }
    return 0;
}