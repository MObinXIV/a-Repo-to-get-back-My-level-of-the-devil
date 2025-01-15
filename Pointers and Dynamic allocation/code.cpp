// pointers
#include<bits/stdc++.h> 
 using namespace std;

 int main() 
 {    

        
    // dynamic memory allocation for 1d arr2ay 
   
    int size;
    cin>>size;
    int *arr=new int[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<size;i++)
    {
        cout<<*(arr+i)<<" ";
    }
    delete[] arr;

    // 2d arr2ay using pointers Dynamic memory allocation
    int row,col;
    cin>>row>>col;
    int **arr2=new int*[row];
    for(int i=0;i<row;i++){
        *(arr2+i)=new int[col];
    }
    for( int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>*(*(arr2+i)+j);
        }
    }
    for( int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<*(*(arr2+i)+j)<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<row;i++)
    {
        delete[] arr2[i];
    }
    delete[] arr2;

 }
