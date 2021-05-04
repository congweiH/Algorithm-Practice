#include <bits/stdc++.h>
using namespace std;

#define int                 int64_t
#define rep(i, a, b)        for(int (i) = (a); i < (b); (i)++)
#define pii                 pair<int, int>
/*
    https://atcoder.jp/contests/zone2021/tasks/zone2021_d
*/
/////////////////////// start code here ///////////////////////////

const int maxn = 10000 + 10;

int n;
string s;
deque<int> q;


void solve(){
    cin >> s;
    bool rev = false;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'R') rev ^= 1;
        else{
            if(rev == true){
                q.push_front(s[i]);
            }else{
                q.push_back(s[i]);
            }
        }
    }
    if(rev == true) reverse(q.begin(), q.end());

    string t = "";

    for(auto c : q){
        if(t == "" || t.back() != c){
            t += c;
        }else if(t.back() == c){
            t.pop_back();
        }
    }
    cout << t << endl;

}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}