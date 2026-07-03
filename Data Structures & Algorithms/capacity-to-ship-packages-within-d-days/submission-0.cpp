class Solution {
private:
    int total(vector<int>nums){
        int total=0;
        for(int i=0; i<nums.size(); i++)total += nums[i];
        return total;
    }

    int daysRequired(vector<int>&nums, int mid){
        int cnt=0, totalDays=1;

        for(int i:nums){
            if(cnt + i > mid){
                cnt=0;
                totalDays++;
            }
            cnt+=i;
        }
        return totalDays;
    }

public:
    int shipWithinDays(vector<int>& nums, int days) {
        int low = *max_element(nums.begin(), nums.end());
        int high = total(nums);

        while(low <= high){
            int mid = low + (high-low)/2;
            int totalDays = daysRequired(nums, mid);
            if(totalDays <= days)high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};