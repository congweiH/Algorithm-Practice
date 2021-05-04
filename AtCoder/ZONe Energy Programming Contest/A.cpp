#include <bits/stdc++.h>
using namespace std;

#define int                 int64_t
#define rep(i, a, b)        for(int (i) = (a); i < (b); (i)++)
#define pii                 pair<int, int>

/////////////////////// start code here ///////////////////////////

const int maxn = 10000 + 10;

int n;
int a[maxn];

void solve(){
    string s;
    cin >> s;

    int count = 0;

    for(int i = 0;i < s.size() - 3; i++){
        string t = "";
        for(int j = 0;j < 4; j++){
            t += s[i+j];
        }
        if(t == "ZONe"){
            count ++;
        }
    }
    cout << count << endl;


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