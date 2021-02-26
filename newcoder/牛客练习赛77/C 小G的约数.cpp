#include <iostream>
using namespace std;

typedef long long ll;


ll G(ll n){
    ll sum = 0;
    for(ll l=1,r; l<=n; l=r+1){
        r = n/(n/l);
        sum += (r-l+1)*(n/l)*(l+r)/2;
    }
    return sum;
}

int main(){

    ll n;
    cin >> n;

    cout << G(G(n)) <<endl;

    return 0;
}