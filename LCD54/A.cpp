#include<bits/stdc++.h>
using namespace std;

//1893. 检查是否区域内所有整数都被覆盖

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool ok[55];
        memset(ok, 0, sizeof(ok));
        for(vector<int> r: ranges){
            for(int i = r[0]; i <= r[1]; i++)
                ok[i] = 1;
        }
        for(int i = left; i <= right; i++){
            if(not ok[i]) return false;
        }
        return true;
    }
};