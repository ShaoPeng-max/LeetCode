#include<bits/stdc++.h>
using namespace std;

//1897. 重新分配字符使所有字符串都相等

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int a[26];
        int n = words.size();
        memset(a, 0, sizeof(a));
        for(string s: words){
            for(char c: s){
                a[c - 'a']++;
            }
        }
        for(int i: a){
            if(i % n) return false;
        }
        return true;
    }
};