#include<bits/stdc++.h>
using namespace std;

// 贪心,每次取不超过target中元素的元组

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> ret{-1, -1, -1};
        for(vector<int> t: triplets){
            bool ok = true;
            for(int i = 0; i < 3; i++) if(t[i] > target[i])
                ok = false;
            if(not ok) continue;
            for(int i = 0; i < 3; i++)
                ret[i] = max(ret[i], t[i]);
            if(ret == target) return true;
        }
        return false;
    }
};