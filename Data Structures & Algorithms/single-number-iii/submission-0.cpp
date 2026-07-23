class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        long xorr = 0;
        for (int i : nums) xorr ^= i;

        int rightmost = (xorr & (xorr - 1)) ^ xorr;

        int xor1 = 0, xor2 = 0;
        for (int i : nums) {
            if (i & rightmost)
                xor1 ^= i;
            else
                xor2 ^= i;
        }
        if(xor1 < xor2) return {xor1, xor2};
        return {xor2, xor1};
    }
};