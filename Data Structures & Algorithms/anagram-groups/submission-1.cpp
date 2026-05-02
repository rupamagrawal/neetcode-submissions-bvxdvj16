class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>temp = strs;
        for(int i=0; i<strs.size(); i++)sort(temp[i].begin(), temp[i].end());

        unordered_map<string, vector<string>>mpp;
        for(int i=0; i<strs.size(); i++)mpp[temp[i]].push_back(strs[i]);

        vector<vector<string>>ans;
        for(auto it: mpp)ans.push_back(it.second);

        return ans;
    }
};
