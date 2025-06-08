//https://leetcode.com/problems/asteroid-collision/description/
#include<bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for (int i = 0; i < asteroids.size(); i++) {
        if (asteroids[i] > 0) // in case of positive I keep push
        {
            st.push(asteroids[i]);
        } else {
            // Process collisions
            while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                st.pop();  // Destroy smaller positive asteroid
            }

            if (st.empty() || st.top() < 0) {
                st.push(asteroids[i]);  // No collision or opposite direction
            } else if (st.top() == abs(asteroids[i])) {
                st.pop();  // Equal size collision
            }
            // else: current asteroid is destroyed, do nothing
        }
    }

    // Output remaining stack to vector in reverse
    vector<int> res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}