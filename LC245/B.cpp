#include<bits/stdc++.h>
using namespace std;

//可移除字符的最大数目
//二分 + 查找

int de[100005];

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& rem) {
        memset(de, 0, sizeof(de));
        int low = 0, high = rem.size();
        while(low < high){
            int mid = (low + high + 1) / 2;
            for(int i = 0; i < mid; i++) de[rem[i]] = 1;
            int j = 0;
            for(int i = 0; i < s.length(); i++){
                if(de[i]) continue;
                if(j < p.length() && s[i] == p[j]) j++;
            }
            for(int i = 0; i < mid; i++) de[rem[i]] = 0;
            if(j == p.length()) low = mid;
            else high = mid - 1;
        }
        return low;
    }
};