class Solution {
private:
    void findCombination(int ind, vector<int>&list,  vector<vector<int>>&ans, vector<int>&nums, int target){
        if(target == 0){
            ans.push_back(list);
            return;
        }
        if(target<=0 || ind==nums.size())return;

        list.push_back(nums[ind]);
        findCombination(ind, list, ans, nums, target-nums[ind]);

        list.pop_back();
        findCombination(ind+1, list, ans, nums, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>list;

        findCombination(0, list, ans, nums, target);
        return ans;
    }
};