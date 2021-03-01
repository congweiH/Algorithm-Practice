#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 1e6 + 10;

int n, u, v;
int a[maxn];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n>>u>>v;
        for(int i = 1;i<=n;i++){
            cin >> a[i];
        }
        bool same = true;
        for(int i = 2;i <=n ;i++){
            if(a[1] != a[i]){
                same = false;
                break;
            }
        }
        if(same == true){
            cout << v  + min(u,v)<<endl;
        }else{
            bool f = true;
            for(int i =1;i<=n-1;i++){
                int r = abs(a[i+1] - a[i]);
                if(r>=2){
                    cout << 0 <<endl;
                    f = false;
                    break;
                }
            }
            if(f==true) cout << min(u,v)<<endl;
        }
    }


    return 0;
}