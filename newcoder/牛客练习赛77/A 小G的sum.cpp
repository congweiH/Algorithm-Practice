
/*
链接：https://ac.nowcoder.com/acm/contest/11160/A
来源：牛客网

给定一个n, 定义mind(n)为n最小的约数，maxd(n)为n最大的约数
求sum i=1..n mind(i) + sum i=1..n maxd(i)

*/


#include <iostream>
using namespace std;

int main(){

    long long n;
    cin >> n;
    cout << n + (1+n)*n/2 <<endl;
    
    return 0;
}