#include <iostream>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;

long long qpow(ll a, ll b){
    ll res = 1;
    for(;b;b>>=1){
        if(b&1) res *= a;
        a *= a;
    }
    return res;
}
map<ll, bool> a;

int main(){

    long long n;
    cin >> n;
    ll cnt = 0;
    ll r = sqrt(n) + 1;
    for(ll i = 2; i <= r; i++){
        for(ll j = 2;j <= r; j++){
            ll t = qpow(i,j);
            if(t > n || t<=0L) break;
            if(a[t] == false){
                cnt ++;
                a[t] = true;
            }
            
        }
    }

    cout << n - cnt << endl;


    return 0;
}