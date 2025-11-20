//https://leetcode.com/problems/spiral-matrix/description/
#include<bits/stdc++.h> 
 using namespace std;
 /**
  * follow the spiral roles in every cycle
  */
 vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();
        vector<int>res;
        
        if(matrix.empty()) return {};
        int top =0, bottom = n-1 , left =0 , right = m-1;
        while(left<=right && top<=bottom){
          // get the right part 
          for(int j = left;j<=right;j++)
          res.push_back(matrix[top][j]);
          top++; // move the pointer down to not repeat the last value in the row when we go down
          // go bottom 
          for(int i = top ;i<=bottom;i++)
          res.push_back(matrix[i][right]);
          right--; // go inside by one for the purpose of not repeat element 
          // if I exhausted say in the first iteration it's a single  row 
          if(top > bottom || left > right) break;
          // left 
          for(int j =right ; j>=left;j--)
          res.push_back(matrix[bottom][j]);
          bottom--; // move one row up as I got my last row completed 
          // move up 
          for (int i = bottom; i >= top; i--) {
            res.push_back(matrix[i][left]);
        }
        left++; // finished the left portion & go inside 
        }
        return res;
        
 }
 int main() 
 {    
    vector<vector<int>> matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int>res= spiralOrder(matrix);
    for(int&it:res)
    cout<<" "<<it;
    
 }

 