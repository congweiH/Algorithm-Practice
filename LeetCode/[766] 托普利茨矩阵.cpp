#include <vector>
using namespace std;

////////////// 下面是答案 ////////////////////

class Solution {
public:
    int n, m;

    bool hasNext(int i, int j){
        if(i + 1 < m && j + 1 < n) return true;
        return false;
    }

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();  // 行 
        n = matrix[0].size();   // 列
        // 行
        for(int j = 0; j < n; j++){
            int curi = 0, curj = j;
            int t = matrix[curi][curj];

            while(hasNext(curi,curj)){
                curi ++; curj ++;
                if(matrix[curi][curj] != t){
                    return false;
                }
            }
        }
        // 列
        for(int i = 0; i < m; i++){
            int curi = i, curj = 0;
            int t = matrix[curi][curj];

            while(hasNext(curi,curj)){
                curi ++; curj ++;
                if(matrix[curi][curj] != t){
                    return false;
                }
            }
        }
        return true;
    }
};