/*
链接：https://ac.nowcoder.com/acm/contest/11160/B
来源：牛客网

小G给你两个数n,k
我们定义F(x)为i从1~x i%k==0的i的和
现在希望你求出sum i=1..n F(i)
*/


#include <iostream>
using namespace std;

long long  n, k;
    
int main(){
    cin >> n >> k;
    long long sum = 0;
    long long res = 0;
    for(long long  i = 1; i<= n;i++){
        if(i%k==0) sum += i;
        res += sum;
    }
    cout << res << endl;
    
    return 0;
}