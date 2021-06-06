#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minWastedSpace(vector<int>& p, vector<vector<int>>& bs) {
        /**
         * 将货物排序
         * 将每个商人的箱子分别排序,然后二分,查找位置,记得保存上一个查找点的位置
        **/
        sort(p.begin(), p.end());
        long long sum = 0;
        for(int i: p) sum += i;
        long long big = (long long)1e18;
        long long ret = big;
        for(vector<int>& b: bs){
            sort(b.begin(), b.end());
            int last = 0;
            long long res = 0;
            if(b[b.size()-1] < p[p.size()-1]) continue;
            for(int s: b){
                if(s < p[last]) continue;
                int lo = upper_bound(p.begin(), p.end(), s) - p.begin();
                res += (long long)s * (lo - last);
                last = lo;
                if(last >= p.size()) break;
            }
            ret = min(ret, res);
        }
        if(ret == big) return -1;
        return (ret - sum) % 1'000'000'007;
        
    }
};