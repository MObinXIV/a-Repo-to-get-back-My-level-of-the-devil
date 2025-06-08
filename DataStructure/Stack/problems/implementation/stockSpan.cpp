//https://leetcode.com/problems/online-stock-span/description/
#include<bits/stdc++.h>
using namespace std;
class StockSpanner {
    stack<pair<int,int>> st;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int k =1;
        while(!st.empty()&& st.top().first<=price)
        {
            k+=st.top().second;
            st.pop();
        }
        st.push({price,k});
        return k;
    }
};
