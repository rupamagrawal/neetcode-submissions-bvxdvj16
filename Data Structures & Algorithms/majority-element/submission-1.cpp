class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int cnt=0;

        for(int n:nums){
            if(cnt==0){
                cnt=1;
                ele=n;
            }else if(n==ele)cnt++;
            else cnt--;
        }
        int cnt1=0;
        for(int n:nums){
            if(n==ele)cnt1++;
        }

        if(cnt1>nums.size()/2)return ele;
        return -1;
    }
};