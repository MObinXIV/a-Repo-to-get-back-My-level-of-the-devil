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