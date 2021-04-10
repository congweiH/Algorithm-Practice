/*
    https://codeforces.com/contest/1491/problem/C
    
    有n个跳床排成一列，第i得跳床得弹力是Si. 你可以跳这些床很多次，可以从任意的位置开始跳。
    如果有一个时刻跳到了第i个床，它会将你弹向第i+Si个床，并且你跳过的每个床的弹力Si会减1, 直到Si=1就不会再减了
    如果在i+Si的位置上没有床，那么这一轮就结束了，除非i+Si大于n，否则你一直跳下去，直到下一个位置没有床，这就算一轮。
    你需要跳最少的轮次将所有跳床的弹力变为1

    输入：t表示多少测试样例
    每一个测试样例包括：跳床的个数n，每个跳床的弹力S[i]

    输出：最少需要跳多少轮
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 5000 + 10;

int n;
int s[maxn];	// 每个床的弹力值
int b[maxn];	// 在这个床上跳的次数


int main(){

	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> s[i];
		}
		long long sum = 0;
		memset(b ,0, sizeof b);
		for(int i = 0; i < n; i++){
			if(s[i] - b[i] - 1 > 0){	// 如果当前的弹床的弹力大于1,那就对次数做出贡献
				sum += (s[i] -  1) - b[i];
			}else{	// 当前的弹力小于1,积累的跳次要想下一个跳床传递
				b[i+1] += b[i] - (s[i] - 1);
			}
			// for(int j = 2; j <= s[i]; j++){    这种写法超时
			// 	if(i+j<=n)
			// 		b[j]++;
			// }
			for(int j = i + 2; j <= min(n, i+s[i]); j++){ //这里为什么i+2, 而不是i+1,是因为s[i]=2才需要跳
				b[j]++;
			}
		}
		cout << sum << endl;

	}
	return 0;
}