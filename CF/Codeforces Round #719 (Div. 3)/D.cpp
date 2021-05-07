#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b)        for(int (i) = (a); (i) <= (b); (i)++)
#define repd(i, b, a)       for(int (i) = (b); (i) >= (a); (i)--)
#define mset(a, x)          memset((a), (x), sizeof (a))

typedef pair<int, int> pii;
typedef long long ll;

/////////////////////////   read me  ///////////////////////////
/*                          
    【url】       https://codeforces.com/contest/1520/problem/D
    【problem】   统计有多少对满足 aj - ai = j - i
    【answer】    aj - ai = j - i ---> aj - j = ai - i
*/
//////////////////////// start code here ///////////////////////

const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;

int n;
int a;

ll C(int n, int m){
    ll res = 1;
    rep(i, 1, m){
        res = res * (n - i + 1) / i;
    }
    return res;
}

void solve(){
    cin >> n;

    map<int, int> num;

    rep(i, 1, n){
        cin >> a;
        num[a - i] ++;
    }
    ll res = 0;
    for(auto ele : num){
        if(ele.second > 1) res += C(ele.second, 2);
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