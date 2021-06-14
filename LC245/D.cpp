#include<bits/stdc++.h>
using namespace std;

// 暴力 + 剪枝

const int N = 30;
const int INF = 0x3f3f3f3f;
int a[N][N][N], b[N][N][N];

class Solution {
public:
    void dfs(int n, int A, int B){
        if(A + B == n + 1){
            a[n][A][B] = b[n][A][B] = 1;
            return;
        }
        if(b[n][A][B] != -1) return;
        int mid = n >> 1;
        int maxs = 1 << mid;
        for(int s = 0; s < maxs; s++){
            int p[2]{1, n};
            vector<int> temp;
            
            for(int i = 0; i < mid; i++, p[0]++, p[1]--){
                int id = (s >> i) & 1;
                int winner = p[id], loser = p[id ^ 1];
                if(loser == A || loser == B) break;
                temp.push_back(winner);
            }
            if(temp.size() < mid) continue;
            if(n & 1) temp.push_back(mid + 1);
            sort(temp.begin(), temp.end());
            int posA = find(temp.begin(), temp.end(), A) - temp.begin() + 1;
            int posB = find(temp.begin(), temp.end(), B) - temp.begin() + 1;
            dfs(temp.size(), posA, posB);
            a[n][A][B] = min(a[n][A][B], a[temp.size()][posA][posB] + 1);
            b[n][A][B] = max(b[n][A][B], b[temp.size()][posA][posB] + 1);
        }
    }
    
    vector<int> earliestAndLatest(int n, int A, int B) {
        memset(a, INF, sizeof(a));
        memset(b, -1, sizeof(b));
        if(A > B) swap(A, B);
        dfs(n, A, B);
        
        return {a[n][A][B], b[n][A][B]};
    }
};