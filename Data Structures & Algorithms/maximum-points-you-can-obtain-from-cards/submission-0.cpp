class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int lSum=0, rSum=0;
        int maxSum=0;

        for(int i=0; i<k; i++)lSum += nums[i];
        maxSum = lSum;
        int right=nums.size()-1;
        for(int i=k-1; i>=0; i--){
            lSum -= nums[i];
            rSum += nums[right--];
            maxSum = max(maxSum , lSum + rSum);
        }
        return maxSum;
    }
};