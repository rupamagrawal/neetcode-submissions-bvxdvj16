class Solution{
public:
    vector<int> asteroidCollision(vector<int> &nums){
        vector<int>ls;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0)ls.push_back(nums[i]);
            else{
                while(!ls.empty() && ls.back()>0 &&
                ls.back() < abs(nums[i]))ls.pop_back();

                if(!ls.empty() && ls.back() == abs(nums[i]))ls.pop_back();
                else if(ls.empty() || ls.back()<0)ls.push_back(nums[i]);
            }
        }
        return ls;
      
    }
};