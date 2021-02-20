

#include <iostream>
#include <string>
using namespace std;

string a[100+10];
int tot;

string y[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};



void fun(int n){
    while(n){
        a[tot++] = y[n%10];
        n/=10;
    }
}


int main()
{
    string n;
    cin>>n;
    int sum = 0;
    for(int i = 0;i<n.length();i++){
        sum+=(n[i]-'0');
    }
    fun(sum);
    for(int i = tot-1; i>0;i--){
        cout<<a[i]<<' ';
    }
    cout<<a[0]<<endl;
    return 0;
}