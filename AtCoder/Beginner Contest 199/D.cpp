#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100 + 10;

int n, m;
int k;  // k 种颜色
// 邻接表
vector<int> G[maxn];
// 0 代表没有涂颜色, 1,2,..,k 表示不同的颜色
int color[maxn];

long long res = 0;  // 方案数, 会很大 用long long

void dfs(int u, long long w){
    if(u > n){
        // 出口，所有顶点涂色完毕
        res += w;
        return;
    }
    // 【小优化】如果该点是个独立的点, 直接贡献乘颜色种类
    if(G[u].size()==0) dfs(u+1, w*k);
    else{
        // 枚举颜色
        for(int i = 1; i <= k; i++){
            // 先检查 u 能不能涂 i 这种颜色
            bool f = true;
            for(int v : G[u]){
                if(color[v] == i){
                    f = false;
                    break;
                }
            }
            if(f == true){
                // 可以涂颜色i
                color[u] = i;
                dfs(u+1, w);
                // 回溯
                color[u] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> m;  // 顶点 和 边
    k = 3;
    // cin >> k;   // k 种颜色
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;      // 编号 1,..,n
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 1);
    cout << res << endl;
    return 0;
}