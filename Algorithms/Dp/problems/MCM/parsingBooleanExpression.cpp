//https://leetcode.com/problems/parsing-a-boolean-expression/
#include<bits/stdc++.h>
#define ll long
using namespace std;
const int mod = 1000000007;

/*
Start by identifying the innermost expression enclosed in parentheses 
and work your way outward, applying the relevant logical operation each time.
*/
 bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char ch : expression) {
            if (ch == ',' || ch == ' ') continue;

            if (ch != ')') {
                st.push(ch);
            } else {
                // Evaluate the expression inside parentheses
                unordered_set<char> operands;
                while (st.top() != '(') {
                    operands.insert(st.top());
                    st.pop();
                }
                st.pop(); // remove '('
                char op = st.top(); st.pop(); // the operator

                char result;
                if (op == '!') {
                    result = (*operands.begin() == 't') ? 'f' : 't';
                } else if (op == '&') {
                    result = operands.count('f') ? 'f' : 't';
                } else if (op == '|') {
                    result = operands.count('t') ? 't' : 'f';
                }
                st.push(result);
            }
        }
        return st.top() == 't';
    }

    int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
    // Base case 1: If i > j, it's an invalid expression, return 0.
    if (i > j) return 0;
    
    // Base case 2: If i and j are the same, evaluate the single character.
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    // If the result for this subproblem has been computed before, return it.
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    ll ways = 0;
    
    // Iterate through the expression.
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = f(i, ind - 1, 1, exp, dp);  // Number of ways to make the left expression true.
        ll lF = f(i, ind - 1, 0, exp, dp);  // Number of ways to make the left expression false.
        ll rT = f(ind + 1, j, 1, exp, dp);  // Number of ways to make the right expression true.
        ll rF = f(ind + 1, j, 0, exp, dp);  // Number of ways to make the right expression false.

        // Check the operator at the current index and update ways accordingly.
        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {  // XOR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    
    // Store the result in the DP table and return it.
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return f(0, n - 1, 1, exp, dp);  // Start evaluation with isTrue set to true.
}
