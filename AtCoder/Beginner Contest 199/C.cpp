#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 200000 + 10;

int n, Q;
string s;
int T,a,b;

int main(){

    cin >> n;
    cin >> s;
    cin >> Q;

    string A = s.substr(0, n);
    string B = s.substr(n ,n);
    // A[0, n-1]
    // B[n, 2*n-1]

    while(Q--){
        cin >> T >> a >> b;
        if(T == 1){
            a-= 1, b-=1;
            if( a >= n && b >= n){
                swap(B[a-n], B[b-n]);
            }else if(a >= n && b < n){
                swap(B[a-n], A[b]);
            }else if(a < n && b >= n){
                swap(A[a], B[b-n]);
            }else{
                swap(A[a], A[b]);
            }
        }else{
            swap(A, B);
        }
    }
    cout << A << B << endl;

    return 0;
}