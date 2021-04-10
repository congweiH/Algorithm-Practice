/*
    https://ac.nowcoder.com/acm/contest/11160/C

    定义 G(n) 为 1-n 所有数的约数和

    计算 G(G(n))
*/


#include <iostream>
using namespace std;

typedef long long ll;


ll G(ll n){
    ll sum = 0;
    for(ll l = 1, r; l <= n; l = r+1){
        r = n/(n/l);
        sum += 1ll*(l+r)*(r-l+1)/2*(n/l);
    }
    return sum;
}


int main(){

    ll n;
    cin >> n;
    cout << G(G(n)) << endl;
    
    return 0;
}