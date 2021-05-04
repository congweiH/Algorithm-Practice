#include <bits/stdc++.h>
using namespace std;

#define int                 int64_t
#define rep(i, a, b)        for(int (i) = (a); (i) <= (b); (i)++)
#define pii                 pair<int, int>

/*
    https://atcoder.jp/contests/zone2021/tasks/zone2021_c
   Problems of the form of “maximum value of minimum value” can sometimes be solved easily by boiling it down to 
   a yes-no problem of “can the answer be more than x?” and do binary search for the answer.
    二分答案 + 二进制状态压缩

*/
/////////////////////// start code here ///////////////////////////

const int maxn = 3000 + 10;

int n;
int a[maxn][10];
int res;

// can the answer be more than x?
bool check(int x){
    set<int> s;
    rep(i, 1, n){
        // 将每个人的状态压缩的二进制, 
        // 例如一个人所有的属性都超过x,那么他对应的二进制是 11111
        int state = 0;  // 00000
        rep(j, 0, 4){
            if(a[i][j] >= x){
                // j 属性超过了x, 那么j 对应的位置是1
                int b = 1 << j;
                state |= b;
            }
        }
        s.insert(state);
    }
    // 暴力枚举3个人
    for(auto a : s) for(auto b : s) for(auto c : s){
        if((a | b | c) == 31){  // 11111
            return true;
        }
    }
    return false;
}

void solve(){

    cin >> n;
    rep(i, 1, n) rep(j, 0, 4) cin >> a[i][j];

    int l = 0, r = INT_MAX;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            res = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << res << endl;
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