class Solution {
public:
    int findMin(vector<int> &nums) {
        int mini = INT_MAX;
        int low=0, high=nums.size()-1;

        // while(low <= high){
        //     int mid = low +(high-low)/2;

        //     if(nums[low] <= nums[high]){
        //         return min(mini, nums[low]);
        //     }
        //     if(nums[low] <= nums[mid]){
        //         mini = min(mini, nums[low]);
        //         low = mid+1;
        //     }
        //     else{
        //         mini = min(mini, nums[mid]);
        //         high = mid-1;
        //     }
        // }
        // return mini;

         while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum lies in the right half
                low = mid + 1;
            } else {
                // Minimum lies in the left half (mid can be the answer)
                high = mid;
            }
        }

        return nums[low];
    }
};
