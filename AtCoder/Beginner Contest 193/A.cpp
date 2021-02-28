#include <iostream>
#include <cstdio>
using namespace std;

int main(){

    double a,b;
    cin >> a >>b;

    double res = (a-b)/a*100;

    printf("%.4lf", res);

    return 0;
}