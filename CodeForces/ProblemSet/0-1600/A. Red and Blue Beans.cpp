#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b)        for(register int (i) = (a); (i) <= (b); (i)++)
#define repd(i, b, a)       for(register int (i) = (b); (i) >= (a); (i)--)
#define mset(a, x)          memset((a), (x), sizeof(a))
#define x                   first
#define y                   second

typedef pair<int, int> pii;
typedef long long ll;

// 重载to_string
template <typename A, typename B>string to_string(pair<A, B> p);template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p);template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p);string to_string(const string& s) {  return '"' + s + '"';}string to_string(const char* s) {  return to_string((string) s);}string to_string(bool b) {  return (b ? "true" : "false");}string to_string(vector<bool> v) {  bool first = true;  string res = "{";  for (int i = 0; i < static_cast<int>(v.size()); i++) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(v[i]);  }  res += "}";  return res;}template <size_t N>string to_string(bitset<N> v) {  string res = "";  for (size_t i = 0; i < N; i++) {    res += static_cast<char>('0' + v[i]);  }  return res;}template <typename A>string to_string(A v) {  bool first = true;  string res = "{";  for (const auto &x : v) {    if (!first) {      res += ", ";    }    first = false;    res += to_string(x);  }  res += "}";  return res;}template <typename A, typename B>string to_string(pair<A, B> p) {  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}
// 声明debug    不能打印普通数组, 自定义结构体
void debug_out() { cerr << endl; }template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {  cerr << " " << to_string(H);  debug_out(T...);}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
// 声明read  ---  只能输入整数数字(int , ll)
template<typename T> void read(T &x){
    x = 0;char ch = getchar();ll f = 1;
    while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
    while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
template<typename T, typename... Args> void read(T &first, Args& ... args) {
    read(first);
    read(args...);
}  // read end
///////////////////////////////   ABOUT  ///////////////////////////
/*
- https://codeforces.com/problemset/problem/1519/A

*/
////////////////////////////// START CODE ///////////////////////

#define int                 long long    // int 变成 long long
const int mod = 1e9 + 7;
const int maxn = 10000 + 10;

void solve(){

    int r, b, d;
    read(r, b, d);

    // debug(r, b, d);

    int minx = min(r, b);
    int manx = max(r, b);

    // debug(manx, minx);

    if(manx <= minx * (d + 1)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

signed main(){
    // freopen("F:\\workspace\\Algorithm-Practice\\input.txt", "r", stdin);
    // freopen("F:\workspace\Algorithm-Practice\output.txt", "w", stdout);

    int T = 1;
    cin >> T;
    rep(i, 1, T){
        //cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}