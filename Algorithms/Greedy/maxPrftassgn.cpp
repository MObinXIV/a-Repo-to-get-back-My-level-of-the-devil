int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(),worker.end());
        vector<pair<int,int>>jobs;
        for(int i = 0;i<difficulty.size();i++){
            jobs.push_back({difficulty[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());// sorting according to difficulty
        int j =0;
        int sum=0;
        int maxi=0;
        for(int i = 0 ; i<worker.size();i++){
            while(j<difficulty.size() && worker[i]>=jobs[j].first)
            {
                maxi=max(jobs[j].second,maxi);
                j++;
            }
            sum+=maxi;
        }
        return sum;
    }