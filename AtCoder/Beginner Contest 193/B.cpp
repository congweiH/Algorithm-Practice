#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1e9 + 10;

int n;
int a, p, x;


int main(){

    cin >> n;

    int res = MAX;
    for(int i = 1; i <= n; i++){
        cin >> a >> p >> x;
        if(a < x){
            res = min(res, p);
        }
    }
    if(res == MAX){
        cout << -1 <<endl;
    }else{
        cout << res <<endl;
    }




    return 0;
}