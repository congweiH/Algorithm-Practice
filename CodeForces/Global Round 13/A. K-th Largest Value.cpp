#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;

int n, q;
int a[maxn];

int main(){
    cin>>n>>q;
    int sum = 0;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        if(a[i]==1){
            sum ++;
        }
    }
    int t, b;
    while(q--){
        cin >> t >> b;
        if(t==1){
            a[b] = 1 - a[b];
            if(a[b]==0){
                sum--;
            }else{
                sum++;
            }
        }else{
            if(b <= sum) cout << 1 <<endl;
            else cout << 0 << endl;
        }
    }


    return 0;
}