//https://leetcode.com/problems/frog-jump/description/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_set<int> st;
    map<pair<int, int>, bool> mp;

public:
    bool canCross(int pos, int jump, int lastStone) {
        if (pos == lastStone) return true;
        if (!st.count(pos) || pos < 0) return false; // allow pos == 0
        if (mp.count({pos, jump})) return mp[{pos, jump}];

        for (int nextJmp : {jump - 1, jump, jump + 1}) {
            if (nextJmp <= 0) continue; // no backward or zero jump
            if (canCross(pos + nextJmp, nextJmp, lastStone))
                return mp[{pos, jump}] = true;
        }

        return mp[{pos, jump}] = false;
    }

    bool canCross(vector<int>& stones) {
        for (int& it : stones)
            st.insert(it);
        return canCross(0, 0, stones.back()); // start from 0 with last jump = 0
    }
};
