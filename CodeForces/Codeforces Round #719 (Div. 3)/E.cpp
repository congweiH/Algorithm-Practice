#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b)        for(register int (i) = (a); (i) <= (b); (i)++)
#define repd(i, b, a)       for(register int (i) = (b); (i) >= (a); (i)--)
#define mset(a, x)          memset((a), (x), sizeof (a))

typedef pair<int, int> pii;
typedef long long ll;

///////////////////////////   about  ///////////////////////////
//
//          https://codeforces.com/contest/1520/problem/E
// 【思路】     找到中间羊的位置，所有羊往中间羊的位置靠
//
//////////////////////// start code here ///////////////////////

const int mod = 1e9 + 7;
const int maxn = 10000 + 10;

int n;
string s;

void solve(){
    cin >> n;
    cin >> s;
    // 记录所有羊的位置
    vector<int> a;
    rep(i, 0, n - 1){
        if(s[i] == '*') a.push_back(i + 1);
    }
    // 没有羊
    if(a.size() == 0) {cout << 0 << endl; return;}
    // 找到中间羊的位置, 如果是偶数，其中一个都可以
    int mid = a.size() / 2;
    int pos = a[mid];
    ll res = 0;
    rep(i, 0, a.size()-1){
        res += (abs(pos - a[i]) - 1) - (abs(mid - i) - 1);
        // cout << "res: " << res << endl;
    }
    cout << res << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}