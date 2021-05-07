#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b)		for(int (i) = (a); (i) < (b); (i)++)


////////////////////////  code  here  ////////////////////////

const int maxn = 1000 + 10;

int n;
string s;


void solve(){
	
	cin >> n;
	cin >> s;
	string t = "";
	
	rep(i, 0, s.size()) {
		if(t == "" || t.back() != s[i]){
			t.push_back(s[i]);
		}else if(t.back() == s[i]){
			
		}
	}
	
//	cout << t << endl;
	
	
	bool f[100];
	memset(f, false, sizeof f);
	bool flag = true;
	rep(i, 0, t.size()) {
		if(f[t[i]-'A'] == true){
			flag = false;
			break;
		}
		f[t[i]-'A'] = true;
	}
	if(flag == true) cout << "YES" << endl;
	else cout << "NO" << endl;
	
}
int main(){
	
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	cin >> T;

	while(T--) solve();

    return 0;
}