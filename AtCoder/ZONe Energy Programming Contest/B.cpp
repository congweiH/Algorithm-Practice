#include <bits/stdc++.h>
using namespace std;

#define int                 int64_t
#define rep(i, a, b)        for(int (i) = (a); i < (b); (i)++)
#define pii                 pair<int, int>

/////////////////////// start code here ///////////////////////////

const int maxn = 100 + 10;

int n, D,H;
int d[maxn];
int h[maxn];

void solve(){

    cin >> n >> D >> H;
    for(int i = 1;i <= n; i++){
        cin >> d[i] >> h[i];
    }
    double res = 0;
    for(int i = 1; i <= n; i++){
        double k = 1.0 * (H - h[i]) / (D - d[i]);
        double y = H - k * D;
        res = max(res, y);
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