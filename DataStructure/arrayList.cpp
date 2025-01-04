// Desinging an array list 
#include<bits/stdc++.h> 
 using namespace std;
template <class T>
class ArrayList{
private:
    T *internalMemory;
    int size;
    int index;
    void expand(){

    size += 10;
        T *temp = new T[size];

        for (int i = 0; i < size; i++)
            temp[i] = internalMemory[i];

        delete[] internalMemory;
        internalMemory = temp;
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
        return internalMemory[index];
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
    list.display();
 }
