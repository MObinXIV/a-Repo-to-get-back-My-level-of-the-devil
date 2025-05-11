//https://leetcode.com/problems/design-twitter/description/
#include <bits/stdc++.h>
using namespace std;
 class Twitter {
    int timeStamp;
    unordered_map<int,vector<pair<int,int>>> tweets;
    unordered_map<int,unordered_set<int>> following;
    
public:
    Twitter() {
        timeStamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        // posting new tweet
        tweets[userId].push_back({timeStamp++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;
        // push the tweets of the user 
        for(auto&it:tweets[userId])
        pq.push(it);

        // add the tweets of the people the user follows
        /**
         * get the ids of the users follwings 
         * get the tweets of them 
         */
        for(int follwedId:following[userId])
        {
            for(auto&it:tweets[follwedId])
            {
                pq.push(it);
            }
        }
        vector<int> news;
        // get the first 10 tweets of the pq 
        for(int i = 0 ; i<10 && !pq.empty();i++)
        {
            news.push_back(pq.top().second);
            pq.pop();
        }
        return news;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};