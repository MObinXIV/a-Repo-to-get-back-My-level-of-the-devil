//https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1 
#include<bits/stdc++.h> 
using namespace std;
//I gurantee that the 1st element is 1 
void solve(int x ,int y, int n, vector<vector<int>>& maze,vector<vector<int>>&visited,string path,vector<string>&res){

  if(x==n-1 && y==n-1) 
  {
    res.push_back(path);
    return;
  }
  
  // down 
  if(x+1<n && visited[x+1][y]==0 && maze[x+1][y]==1)
  {visited[x][y]=1;
    solve(x+1,y,n,maze,visited,path+'D',res);
    visited[x][y]=0;

  }
   

  // left
  if(y-1>=0 && visited[x][y-1]==0 && maze[x][y-1]==1)
    {visited[x][y]=1;
      solve(x,y-1,n,maze,visited,path+'L',res);
      visited[x][y]=0;

    }
 

  //right
  if(y+1<n && visited[x][y+1]==0 && maze[x][y+1]==1)
    {
      visited[x][y]=1;
      solve(x,y+1,n,maze,visited,path+'R',res);
      visited[x][y]=0;

    }


  //up
  if(x-1>=0 && visited[x-1][y]==0 && maze[x-1][y]==1)

    {
      visited[x][y]=1;
      solve(x-1,y,n,maze,visited,path+'U',res);
      visited[x][y]=0;

    }
 

}
vector<string> ratInMaze(vector<vector<int>>& maze) {
  // if the first element is 0 I gurantee there's no path to go on 
  int n = maze.size();
  vector<vector<int>> vis(n,vector<int>(n,0));
  vector<string>res;
  if(maze[0][0]==1) solve(0,0,n,maze,vis,"",res);
  return res;

  
}
int main() 
 {    
    vector<vector<int>>maze= {{1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
    vector<string> res = ratInMaze(maze);
    for(auto &it:res)
    cout<<it<<" ";
 }