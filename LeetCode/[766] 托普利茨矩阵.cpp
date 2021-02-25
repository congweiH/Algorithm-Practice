#include <vector>
using namespace std;
/*
    题目大意：检查一个矩阵是否是斜着都是一样的

*/

////////////// 第一次写的答案 ////////////////////

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

////////////// 第二次写的答案 ////////////////////
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();  // 行 
        int n = matrix[0].size();   // 列
        
        for(int i = 0; i+1 < m; i++){
            for(int j = 0; j+1 < n; j++){
                if(matrix[i][j] != matrix[i+1][j+1])
                    return false;
            }
        }

        return true;

    }
};