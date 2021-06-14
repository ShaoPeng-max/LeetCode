#include<bits/stdc++.h>
using namespace std;

//1895. 最大的幻方

class Solution {
public:
    int m, n;
    int ret = 1;
    bool equal(vector<vector<int>>& grid, int x, int y, int l){
        int sum = 0;
        for(int i = x; i < x + l; i++){
            sum += grid[i][y];
        }
        for(int i = x; i < x + l; i++){
            int res = 0;
            for(int j = y; j < y + l; j++){
                res += grid[i][j];
            }
            if(res != sum) return false;
        }
        for(int j = y; j < y + l; j++){
            int res = 0;
            for(int i = x; i < x + l; i++){
                res += grid[i][j];
            }
            if(res != sum) return false;
        }
        int r1 = 0, r2 = 0;
        for(int i = 0; i < l; i++){
            
            r1 += grid[x+i][y+i]; r2 += grid[x+i][y+l-1-i];
        }
        return r1 == sum && r2 == sum;
    }
    int valid(vector<vector<int>>& grid, int x, int y){
        int len = min(m - x, n - y);
        for(int l = len; l >= 1; l--){
            if(l > ret && equal(grid, x, y, l)) return l;
        }
        return 1;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ret = max(ret, valid(grid, i, j));
            }
        }
        return ret;
    }
};