class Solution {
private:
    void findCombination(int ind, vector<int>&list,  vector<vector<int>>&ans, vector<int>&nums, int target){
        if(target == 0){
            ans.push_back(list);
            return;
        }
        if(target<=0 || ind==nums.size())return;

        list.push_back(nums[ind]);
        findCombination(ind+1, list, ans, nums, target-nums[ind]);
        list.pop_back();
        
        for(int j=ind+1; j<nums.size(); j++){
            if(nums[j] != nums[ind]){
                findCombination(j, list, ans, nums, target);
                break;
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>list;
        sort(nums.begin(), nums.end());
        findCombination(0, list, ans, nums, target);
        return ans;
    }
};