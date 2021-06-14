#include<bits/stdc++.h>
using namespace std;

//1896. 反转表达式值的最少操作次数
// 树dp,自底向上

struct Node{
    char ch; // signal
    int ret; // the result
    int cos; // the cost
};

int INF = INT_MAX;

class Solution {
public:
    stack<Node> stk;
    void calc(){
        while(stk.size() > 1){
            Node a = stk.top(); stk.pop();
            Node op = stk.top(); stk.pop();
            if(op.ch == ')'){
                stk.push(a);
                return;
            }
            Node b = stk.top(); stk.pop();
            op.ret = op.ch == '&' ? a.ret & b.ret : a.ret | b.ret;
            if(a.ret != b.ret) op.cos = 1;
            else if(a.ret == 1){
                int res = min(a.cos, b.cos);
                op.cos = op.ch == '&' ? res : res + 1;
            }
            else if(a.ret == 0){
                int res = min(a.cos, b.cos);
                op.cos = op.ch == '|' ? res : res + 1;
            }
            stk.push(op);
        }
    }
    int minOperationsToFlip(string exp) {
        int n = exp.size();
        for(int i = n-1; ~i; i--){
            if(exp[i] == ')' || exp[i] == '&' || exp[i] == '|'){
                Node node{exp[i], -1, INF};
                stk.push(node);
            }
            else if(exp[i] == '(') calc();
            else{
                Node node{exp[i], exp[i] - '0', 1};
                stk.push(node);
            }
        }
        calc();
        return stk.top().cos;
    }
};