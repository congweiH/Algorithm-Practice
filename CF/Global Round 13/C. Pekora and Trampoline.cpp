#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;

int n;
ll a[5010], b[5010];

int main(){
    int t;
    cin >> t;
    while (t --){
        cin >> n;
        for(int i = 1;i<=n;i++) cin >> a[i];
        memset(b, 0, sizeof b);
        ll res = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] - 1 > b[i]){
                res += a[i] - 1 - b[i];
            }
            //if这个位置的弹力早已经到1了,多出来的次数(b[i]-a[i]+1)叠加到下一个弹床(因为跳弹力为1的弹床,将到达相邻的下一个位置(i+1))
            if(a[i] - 1 < b[i]){    
                b[i+1] += b[i] - a[i] + 1;
            }
            for(int j=i+2; j <= min((ll)n,i+a[i]); j++) b[j] ++;
        }
        cout << res << endl;
    }
    

    return 0;
}