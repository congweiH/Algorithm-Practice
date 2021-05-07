#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b)		for(int (i) = (a); (i) < (b); (i)++)


////////////////////////  code  here  ////////////////////////

const int maxn = 100 + 10;

int n;
int a[maxn][maxn];

void solve(){
	
	cin >> n;
	
	if(n == 1){
		cout << 1 << endl;
	}else if(n == 2){
		cout << -1 << endl;
	}else{
		int r = 1, c = 1, p = 1;
		rep(i, 1, n+1){
			r = 1;
			c = i;
			int y = n;
			while(y--){
				a[r][c] = p++;
				r ++; c ++;
				if(c > n) c = 1;
			}
		}
		rep(i, 1, n+1){
			rep(j ,1, n + 1){
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}
	}
	
}


int main(){
	
	cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;

	while(t--) solve();


    return 0;
}