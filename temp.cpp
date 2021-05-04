#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1000 + 10;

int n, k;
int a[maxn];

int res;

int main(){

	cin >> n;
	// cin >> k;
	k = 3;

	for(int i = 0; i < n; i++) cin >> a[i];

	int l = 0, r = n-1;
	while(l <= r){
		int mid = (l + r) / 2;
		if(a[mid] >= k){
			res = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	// 此时 l
	cout << res << endl;
	return 0;
}