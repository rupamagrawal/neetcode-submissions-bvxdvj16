class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<bool>vis(n, false);
        vector<int>temp;

        solve(nums, ans, vis, temp);
        return ans;
    }

    void solve(vector<int>&nums, vector<vector<int>>&ans, vector<bool>&vis, vector<int>&temp){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!vis[i]){
                temp.push_back(nums[i]);
                vis[i] = true;
                solve(nums, ans, vis, temp);

                //backtrack
                temp.pop_back();
                vis[i] = false;

            }
        }
    }
};
