//https://leetcode.com/problems/expression-add-operators/description/
#include<bits/stdc++.h>
using namespace std;
void f(string& num, int target, int ind, long value, long prev, string path, vector<string>& res) {
    if (ind == num.size()) {
        if (value == target) res.push_back(path);
        return;
    }
    for (int i = ind; i < num.size(); i++) {
        if (i != ind && num[ind] == '0') break;
        string curExpr = num.substr(ind, i - ind + 1);
        long curr = stol(curExpr);
        if (ind == 0) {
            f(num, target, i + 1, curr, curr, curExpr, res);
        } else {
            // Always append to path (left-to-right)
            f(num, target, i + 1, value + curr, curr, path + "+" + curExpr, res); // Addition
            f(num, target, i + 1, value - curr, -curr, path + "-" + curExpr, res); // Subtraction
            f(num, target, i + 1, value - prev + prev * curr, prev * curr, path + "*" + curExpr, res); // Multiplication
        }
    }
}
vector<string> addOperators(string num, int target) {
        vector<string>res;
        if(num.empty()) return res;
        f(num,target,0,0,0,"",res);
        return res;
    }