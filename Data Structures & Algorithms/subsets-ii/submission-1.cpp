class Solution {
    private:
    void subset(int ind, vector<int>&list, vector<vector<int>>&ans, vector<int>&nums ){
        if(ind==nums.size()){
            ans.push_back(list);
            return;
        }

        list.push_back(nums[ind]);
        subset(ind+1, list, ans, nums);
        list.pop_back();
        
        for(int i=ind+1; i<nums.size(); i++){
            if(nums[i]!=nums[ind]){
                subset(i, list, ans, nums);
                return;
            }
        }
        subset(nums.size(), list, ans, nums);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>list;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        subset(0, list, ans, nums);
        return ans;
    }
};
