class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n, 0);
        int posInd=0, negInd=1;

        for(int num:nums){
            if(num<0){
                arr[negInd]=num;
                negInd+=2;
            }else{
                arr[posInd]=num;
                posInd+=2;
            }
        }
        return arr;
    }
};