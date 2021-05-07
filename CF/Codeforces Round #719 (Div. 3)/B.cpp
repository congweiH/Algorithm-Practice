#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b)		for(int (i) = (a); (i) < (b); (i)++)


////////////////////////  code  here  ////////////////////////

const int maxn = 1000 + 10;

int n;
vector<int> a;


int len(int n){
	int sum = 0;
	while(n){
		n/=10;
		sum++;
	}
	return sum;
}

int chu(int len){
	len--;
	int res = 1;
	while(len--){
		res = 10*res + 1;
	}
	return res;
}

void solve(){
	
	
	cin >> n;
	
	if(n <= 9){
		cout << n << endl;
	}else{
		cout << 9 * (len(n) - 1) + n / chu(len(n)) << endl;
	}
	
	
}


int main(){
	
	cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;

	while(t--) solve();


    return 0;
}