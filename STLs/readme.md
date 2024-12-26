# STL


let's work with code snippets to make use of each container,

----

## Pair:



`// normal pair
       pair<int,int> p = {1,2};
       cout<<p.first<<" "<<p.second<<endl;
       // pair of pair
       pair<int,pair<int,int>> p1 = {1,{2,3}};
       cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;
       // pair of array
         pair<int,char> p2[] = {{1,'a'},{3,'b'},{5,'c'}};
         // print the pair of array
            for (auto it : p2)
            {
                cout<<it.first<<" "<<it.second<<endl;
            }`

`//Vectors
    vector<pair<int,int>>v;
    v.push_back({0,0}); v.push_back({2,0});
    for (auto it:v)
     cout<<it.first<<" "<<it.second<<endl;
   // fill the vector with 0 in fixed size
    vector<int> v1(5,0);
    v1[2]=2;
    for (auto it:v1)
    cout<<it<<" ";
    cout<<endl;
    // Copy vector to another one 
    /// Iterator -> It's points to the memory where the element is stored
    vector<int> v2(v1);
    for (auto it:v2)
    cout<<it<<" ";
    cout<<endl; 
    // iterate over vector
    vector<int> ::iterator it = v1.begin();
    it+=2; // move the iterator to the 3rd element
    cout<<*it<<endl;//print the 3rd element using iterator
    // earse single element in array 
   vector<int> v = {1, 2, 3, 4, 5};
    v.erase(v.begin() + 2);
    v.erase(v.begin() + 2, v.begin() + 4);
    for(auto i : v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    vector v1 = {1, 2, 3, 4, 5};
// insert single element in array using insert function
v1.insert(v1.begin()+1 , 3); // insert it in the first line 
    v1.insert(v1.begin()+2 , 3,9); // insert it after the second indext 3 occurences of 9
    for(auto i : v1)
    {
        cout<<i<<" ";
    }
    v.swap(v1);  // swap vectors
    v.pop_back();// pop the last element
    v.clear(); // clear the vector`