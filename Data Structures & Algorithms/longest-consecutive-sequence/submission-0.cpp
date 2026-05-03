class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1)return n;

        int longest = 1;
        unordered_set<int>st;
        for(int i: nums)st.insert(i);

        for(auto it: st){
            if(st.find(it-1) == st.end()){
                int cnt=1;
                int num=it;
                while(st.find(num+1) != st.end()){
                    cnt++;
                    num++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};
