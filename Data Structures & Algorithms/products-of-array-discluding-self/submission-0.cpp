class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
 int prod = 1;
        int zero= 0;
        int ind = -1;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                zero++;
                ind = i;
            }else prod *= nums[i];
        }

        vector<int>ans(n, 0);
        for(int i=0; i<n; i++){
            if(zero==0){
                ans[i] = prod/nums[i];
            }else if(zero==1){
                ans[ind] = prod;
            }
        }
        return ans;
    }
};
