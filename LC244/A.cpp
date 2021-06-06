#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        /**
         * 将原矩阵顺时针旋转90度
         * 令原矩阵为mat, 暂存矩阵为temp
         * 则temp[i][j] = mat[n-1-j][i]
         * 即第i行,j列为原矩阵的第倒数第j行,i列
        **/
        int n = mat.size();
        vector<vector<int>> temp(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0, k = n - 1; j < n; j++, k--){
                temp[i][j] = mat[k][i];
            }
        }
        mat = temp;   
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        /**
         * 将矩阵旋转4次,判断每次是否相等
        **/
        int t = 4;
        while(t--){
            if(mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};
