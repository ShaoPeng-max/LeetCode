#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        /**
         * ret 返回总步骤
         * 先将原数组排序,标记好最小值
         * cur = 变为最小值的次数,每当遇到新的值+1
         * 每个num ret += cur
        **/
        int ret = 0;
        sort(nums.begin(), nums.end());
        int tar = nums[0];
        for(int i = 1, cur = 0; i < nums.size(); i++){
            if(nums[i] != tar){
                cur++;
                tar = nums[i];
            }
            ret += cur;
        }
        return ret;
    }
};