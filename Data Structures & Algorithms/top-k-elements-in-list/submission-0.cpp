class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int& it: nums)mpp[it]++;

        vector<vector<int>>bucket(nums.size()+1);
        for(auto&it : mpp)bucket[it.second].push_back(it.first);

        vector<int>res;
        for(int i=bucket.size()-1; i>=0 && res.size()<k; i--){
            for(int n : bucket[i])res.push_back(n);
        }
        return res;
    }
};
