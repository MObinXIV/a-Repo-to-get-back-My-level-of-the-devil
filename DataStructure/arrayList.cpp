// Desinging an array list 
#include<bits/stdc++.h> 
 using namespace std;
template <class T>
class ArrayList{
private:
    T *internalMemory;
    int size;// Total allocated capacity
    int index;// Number of actual elements

    void expand(){

    
        T *temp = new T[size+10];

        for (int i = 0; i < size; i++)
            temp[i] = internalMemory[i];

        delete[] internalMemory;
        internalMemory = temp;
        size += 10;
 }
public:
 ArrayList(){
     size=10;
     index=0;
     internalMemory=new T[size];
 }
 ArrayList(int size){
     this->size=size;
     index=0;
     internalMemory=new T[size];
 }
 void add(T element){
    if(index==size){
        expand();
    }
    internalMemory[index]=element;
    index++;
 }
 void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Index is out of range");
        }

        for (int i = index; i < size - 1; i++)
        {
            // Shift all elements after the specified index one position to the left.
            internalMemory[i] = internalMemory[i + 1];
        }

        size--;
    }
    T&operator[](int ind){
        if(ind<0||ind>=size){
            throw out_of_range("Index is out of range");
        }
        return internalMemory[ind];
    }
    int getSize(){
        return size;
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<internalMemory[i]<<" ";
        }
        cout<<endl;
    }
    void clear(){
        size=10;
        index=0;
        delete[] internalMemory;
        internalMemory=new T[size];
    }
    ~ArrayList(){
        delete[] internalMemory;
    }
};
 
 int main() 
 {    
    ArrayList<int> list;
    for (int i = 0; i < 20; i++)
    {
        list.add(i);
    }
    // list.display();
    for(int i =0 ; i<list.getSize();i++)
    cout<<list[i]<<" ";
 }
