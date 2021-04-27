#include <iostream>
#include <cmath>
using namespace std;

const int maxn = 100 + 10;

int a[maxn];
int b[maxn];

int main(){

    int n;
    cin >> n;
    int low = 0;
    for(int i =0;i<n;i++){
        cin >> a[i];
        low = max(a[i], low);
    }
    int high = 10000;
    for(int i =0;i<n;i++){
        cin >> b[i];
        high = min(high, b[i]);
    }
    int res = high - low + 1;
    if(res <= 0 ){
        cout << 0 << endl;
    }else
    cout << high - low + 1 << endl;
    return 0;
}