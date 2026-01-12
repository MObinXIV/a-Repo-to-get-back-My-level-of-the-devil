//https://leetcode.com/problems/different-ways-to-add-parentheses/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<string,vector<int>>memo;
public:
    vector<int> diffWaysToCompute(string expression) {
        // in case we found the expression we return it 
        if(memo.find(expression)!=memo.end()) return memo[expression];

        vector<int>res;
        //go split at each operator 
        for(int i =0;i<expression.size();i++){
            char c=expression[i];
            // split in each possible operator 
            if(c=='-'||c=='*'||c=='+'){
                //divide 
                string leftPart= expression.substr(0,i);
                string rightPart=expression.substr(i+1);
                // conquer 
                // get all possible results from the left part->solve left
                vector<int>left = diffWaysToCompute(leftPart);
                // get all possible results from right part 
                vector<int>right = diffWaysToCompute(rightPart);//solve right
                // === COMBINE ===
                // Apply current operator to all combinations of left  right
                for(int&leftVal:left)
                {
                    for(int&rightVal:right){
                        if(c=='+') res.push_back(leftVal+rightVal);
                        else if(c=='-') res.push_back(leftVal-rightVal);
                        else if(c=='*') res.push_back(leftVal*rightVal);

                    }
                }
            }
        }
        // base case if no expression is found it's just number 
        if(res.empty()) res.push_back(stoi(expression));
        return memo[expression] = res;
    }

};
