#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;


long long res;

int main(){

    int n;
    cin >> n;
    int w, score;
    for(int i= 1; i <= n; i++){
        cin >> w >> score;
        res += w * score;
    }

    if(res < 0L){
        cout << 0 <<endl;
    }else{
        cout << res <<endl;
    }

    return 0;
}