#include <vector>
using namespace std;
//////////////////////  第一次写的答案  //////////////////////////
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        
        int n = customers.size();
        vector<int> cus(n+1, 0);    // 1-n
        vector<int> gru(n+1, 0);    // 1-n
        for(int i = 0; i < n; i++){
            cus[i+1] = customers[i];
            gru[i+1] = grumpy[i];
        }

        vector<int> sumc(n+1, 0);
        vector<int> sumg(n+1, 0);
        vector<int> g(n+1, 0);  
        for(int i = 1 ; i <= n; i++){
            if(gru[i]==0){
                g[i] = cus[i];
            }
            sumc[i] = sumc[i-1] + cus[i];
        }
        for(int i = 1; i <= n; i++){
            sumg[i] = sumg[i-1] + g[i];
        }
        if(X>=n){
            return sumc[n];
        }
        int res = 0;
        for(int start = 1; start + X-1 <= n; start++){
            res=max(res,sumg[n]+(sumc[start+X-1]-sumc[start-1])-(sumg[start+X-1]-sumg[start-1]));
        }
        return res;
    }
};
////////////////////// 第二次写的答案 //////////////////////////////////
// 滑动窗口
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        
        int n = customers.size();
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0){
                sum += customers[i];
                customers[i] = 0;
            }
        }
        int value = 0;
        for(int i = 0; i < X; i++) value += customers[i];
        int maxvalue = value;
        for(int i = 0; i < n-X; i++){
            value = value + customers[i+X] - customers[i];
            if(value > maxvalue){
                maxvalue = value;
            }
        }
        return sum + maxvalue;

    }
};