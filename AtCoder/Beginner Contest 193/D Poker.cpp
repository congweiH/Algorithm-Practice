/*
    https://atcoder.jp/contests/abc193/tasks/abc193_d

    有9*k张牌，9种牌，分别写着1,...9, 每一种牌有k张
    先洗牌，然后Jack和Tom分别从中选5张牌，4张朝上，1张朝下
    我们对5张牌定义一个分数，score = sum{ (i*10^(Ci)) }, i = 1,2...,9, ci是第i张牌上的数字
    如果Jack的分数比Tom高，那么就是Jack赢，计算Jack赢的概率

    输入：
        K   表示每一种牌的数量
        S   Jack拿的牌，5个字符，其中前4个字符是1-9的数字，最后一个字符是#
        T   Tom拿的牌
    输出：
        Jack赢的概率
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;

int k;
char s[10];
char t[10];
int used[10]; // 统计1-9张牌已经用掉多少张

// 计算分数
long long score(char a[], int x){
	// 5张牌里面每种牌有多少张
	vector<int> c(10);      // 比 int 方便，少了memset操作
	for(int i = 1;i <= 4; i++){
		c[a[i]-'0']++;
	}
	c[x]++;
	long long sum = 0;
	for(int i = 1; i <= 9; i++){
		sum += i * pow(10, c[i]);
	}
	return sum;
}

int main(){

	cin >> k;
	cin >> s+1;	// 第一个字符在s[1]
	cin >> t+1;

	for(int i = 1; i <= 4; i++){
		used[s[i]-'0']++;
		used[t[i]-'0']++;
	}
	long long sum = 0;  // 一共可行的拿法
	long long win = 0;	// 拿法中jack赢得方案数
	for(int i = 1; i <= 9; i++){	// 第一个人拿的是i
		for(int j = 1; j <= 9; j++){  //第二个人拿的是j
			if(i == j){	// 两个人拿的是同一张牌
				if(used[i]+2 <= k){	// 每一种牌最多k张, 如果满足要求
					// 两个人拿同一张牌，一共有A_{k-used[i]}^{2}种拿法
					sum += 1ll * (k-used[i]) * (k-used[i]-1);   //【注意】这里会爆long long
					long long scorei = score(s, i);
					long long scorej = score(t, j);
					if(scorei > scorej){ 
						win += 1ll * (k-used[i]) * (k-used[i]-1);
					}
				}
			}else{	// 两个人拿不一样的牌
				if(used[i] + 1<= k && used[j] + 1 <= k){
					// 两个人拿不同的牌的方案数是 (k-used[i])*(k-used[j])
					sum += 1ll * (k-used[i]) * (k-used[j]);
					long long scorei = score(s, i);
					long long scorej = score(t, j);
					if(scorei > scorej){
						win += 1ll *  (k-used[i]) * (k-used[j]);
					}
				}
			}
		}
	}
	// cout << win << endl;
	// cout << sum << endl;
	printf("%.5lf\n", 1.0*win/sum);

	return 0;
}