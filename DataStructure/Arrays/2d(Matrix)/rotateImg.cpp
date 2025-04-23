//https://leetcode.com/problems/rotate-image/description/
#include<bits/stdc++.h> 
 using namespace std;

 /*
 transpose -> convert a row to column 
 reverse each row 
 */
 void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose 
        for(int i =0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            swap(matrix[i][j],matrix[j][i]);
        }

        // reverse each row

        for(int i =0;i<n;i++)
        {
            int l=0,r=n-1;
            while(l<r)
            {
                swap(matrix[i][l],matrix[i][r]);
                l++;
                r--;
            }
        }

        // for (int i = 0; i < n; ++i)
        // reverse(matrix[i].begin(), matrix[i].end());
 }
 
 int main() 
 {    
    vector<vector<int>> matrix={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(matrix);
    for(const auto&v:matrix)
    {
        for(const auto&it:v)
        cout<<it<<" ";
        cout<<endl;
    }
 }



 