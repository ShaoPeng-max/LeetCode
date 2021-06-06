#include<bits/stdc++.h>
using namespace std;

int pre[100005][2];
int sub[100005][2];

class Solution {
public:
    int minFlips(string s) {
        /**
         * pre[i][0] 将第i个变为0的最小操作次数 pre[i][1] 将第i个变为1的最小操作次数
         * pre[i][j] = pre[i-1][1-j](与前缀不相同) + s[i] != 'j' ? 1 : 0 (当前要操作的次数)
         * 后缀同理
         * 当 s.size() 为偶数时, 只有0101....01 或 1010...10两种情况
         * 否则有01010100....01 或 101010111...010两个种情况,其中00,11位置要分别枚举
         * 即在11或00的位置分开,前后都是交替字符串,分别枚举两个相交字符串的最小操作数
        **/
        int n = s.size();
        memset(pre, 0, sizeof(pre));
        memset(sub, 0, sizeof(sub));
        for(int i = 0; i < n; i++){
            pre[i][0] = (i == 0 ? 0 : pre[i-1][1]) + (s[i] == '1' ? 1 : 0);
            pre[i][1] = (i == 0 ? 0 : pre[i-1][0]) + (s[i] == '0' ? 1 : 0);
        }
        int ans = min(pre[n-1][0], pre[n-1][1]);
        if(n & 1 ^ 1) return ans;
        for(int i = n-1; i > -1; i--){
            sub[i][0] = (i == (n-1) ? 0 : sub[i+1][1]) + (s[i] == '1' ? 1 : 0);
            sub[i][1] = (i == (n-1) ? 0 : sub[i+1][0]) + (s[i] == '0' ? 1 : 0);
        }
        for(int i = 0; i < n - 1; i++){
            ans = min(ans, pre[i][0] + sub[i+1][0]);
            ans = min(ans, pre[i][1] + sub[i+1][1]);
        }
        return ans;
    }
};