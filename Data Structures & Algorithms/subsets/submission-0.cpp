class Solution {
     private:
     void func(int ind, vector<int> &listt, vector<vector<int>> &ans,
                  vector<int> &nums, int n) {
        if (ind == n) {
            ans.push_back(listt);
            return;
        }
        func(ind + 1, listt, ans, nums, n);

        listt.push_back(nums[ind]);
        func(ind + 1, listt, ans, nums, n);

        listt.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       int n = nums.size();
        vector<int> listt;
        int ind = 0;
        vector<vector<int>> ans;

        func(ind, listt, ans, nums, n);
        return ans;
    }
};
