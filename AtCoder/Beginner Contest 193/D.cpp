#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;

ll k;
// 居然一开始开s[5], t[5], 好傻的我
char s[10], t[10];

ll a[10];

ll getscore(char s[]){
    ll sum = 0;
    int t[10];
    memset(t, 0, sizeof t);
    for(ll i=0;i<5;i++){
        t[s[i]-'0']++;
    }
    for(ll i=1;i<=9;i++){
        sum += i * pow(10, t[i]);
    }
    return sum;
}

int main(){

    cin >> k;
    cin >> s >> t;

    for(int i = 0;i<4;i++){
        a[s[i]-'0']++;
        a[t[i]-'0']++;
    }
    
    ll tot = 0;     // 总的匹配方案
    ll count = 0;   // 第一个赢的方案


    for(ll i = 1;i <= 9; i++){    // 第一个人拿了i
        for(ll j = 1 ;j <= 9; j++){  // 第二个人拿了j
            if(i==j){   // 他们拿着同一张牌
                if(a[i] + 2L <=k){
                    // 说明可以这样拿
                    ll canuse = k - a[i];   // 剩下
                    tot += canuse * (canuse-1L);
                    s[4] = i + '0';
                    t[4] = j + '0';
                    ll score1 = getscore(s);
                    ll score2 = getscore(t);
                    if(score1 > score2) count += canuse * (canuse-1L);
                }
            }else{   // 拿着不同的牌
                if(a[i]< k && a[j] < k){
                    // 说明可以这样拿
                    ll canuesi = k-a[i];
                    ll canuesj = k-a[j];
                    tot += canuesi * canuesj;
                    s[4] = i + '0';
                    t[4] = j + '0';
                    ll score1 = getscore(s);
                    ll score2 = getscore(t);
                    if(score1 > score2) count +=canuesi * canuesj;
                }
            }
        }
    }


    ////////////////////////  第一次写的思路  //////////////////
    // for(int i = 1; i <= 9; i++){
    //     if(a[i] < k){
    //         // 第一个人拿了i这张牌
    //         int b[10];
    //         for(int j = 1; j <= 9; j++) b[j] = a[j];
    //         b[i] ++;    // a的副本
    //         s[4] = i + '0';
    //         int sum = getscore(s); //第一个人的分数

    //         for(int j=1;j<=9;j++){
    //             if(b[j] < k){
    //                 // 说明第二个人可以拿这张牌
    //                 tot ++;

    //                 t[4] = j+'0';
    //                 int sum2 = getscore(t);

    //                 if(sum > sum2) count++;
    //             }
    //         }

    //     }
    // }
    
    long double res = (long double)1.0 * count / tot; 


    printf("%.10Lf\n",res);



    return 0;
}