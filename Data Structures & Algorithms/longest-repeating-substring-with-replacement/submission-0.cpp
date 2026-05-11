class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0, l=0;
        int maxLen=0, maxF=0;
        int hash[26] = {0};

        while(r<s.length()){
            hash[s[r]-'A']++;
            maxF = max(maxF, hash[s[r]-'A']);

            if((r-l+1)-maxF > k){
                hash[s[l]-'A']--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};
