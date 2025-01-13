//https://www.naukri.com/code360/problems/allocate-books_1090540
#include<bits/stdc++.h>
using namespace std;
// function count the number of students to get pages 
int countStudents(vector<int>&arr,int pages){
    int stu=1;
    int stuPages=0;
    // check the possiblity to give the student the maximum pages of books
    for(int&it:arr){
        if(stuPages+it<=pages) // check if I can add more books to the current student
        stuPages+=it;
        // in case if I can't do so I allocate new student
        else
        {stu++;
        stuPages=it;
        }
    }
    return stu;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int low=*max_element(arr.begin(),arr.end());
    int high= accumulate(arr.begin(),arr.end(),0);
    while(low<=high){
        int mid=(low+high)/2;
        int geneMid=countStudents(arr,mid);// Count the number of students required for 'mid' pages
        if(geneMid>m)//if the number of students to take books overflow the number of books increase pages
            {
                low=mid+1;
            }
            else 
            high = mid - 1;
    }
    return low;
}
int main()
{
  vector<int>arr={12, 34, 67, 90};
  
  int n = arr.size(); // Number of books
    int m = 2; // Number of students
    cout << findPages(arr, n, m) << endl;
}

