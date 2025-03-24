// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
#include<bits/stdc++.h> 
 using namespace std;
 int countStudents(vector<int>& students, vector<int>& sandwiches) {
      int cnt =0;
      queue <int>q;
      for(int&it:students)
      q.push(it);
      int i = 0 ; 
      while(!q.empty()&&cnt<q.size()){
        
            if(q.front()!=sandwiches[i]){

                int x = q.front();    
                q.pop();
                q.emplace(x);
                cnt++;
            }
            else {
                q.pop();
                cnt=0;
                i++;
                
            }
      }
      return q.size();

 }
 int main() 
 {    
    vector<int>students={1,1,1,0,0,1}, sandwiches={1,0,0,0,1,1};
    cout<<countStudents(students,sandwiches);
 }
