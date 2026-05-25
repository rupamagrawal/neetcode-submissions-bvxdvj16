class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() <= 1)return -1;

        int s = nums[0];
        int f = nums[nums[0]];

        while(f != s){
            f = nums[nums[f]];
            s= nums[s];
        }
        f=0;
        while( f != s){
            f = nums[f];
            s = nums[s];
        }

        return f;
    }
};
