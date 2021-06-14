#include<bits/stdc++.h>
using namespace std;

//1894. 找到需要补充粉笔的学生编号

using ll = long long;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ll res = 0;
        for(int i: chalk) res += i;
        k %= res;
        for(int i = 0; i < chalk.size(); i++){
            k -= chalk[i];
            if(k < 0) return i;
        }
        return 0;
    }
};