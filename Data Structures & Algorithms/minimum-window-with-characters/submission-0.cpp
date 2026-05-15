class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size();
        int n=t.size();
        if(m<n)return "";

        int sInd = -1;
        int l=0, r=0;

        int hash[256] = {0};
        for(char c:t)hash[c]++;

        int cnt=0;
        int minLen = INT_MAX;

        while(r < m){
            if(hash[s[r]] > 0)cnt++;
            hash[s[r]]--;

            while(cnt == n){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sInd = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0)cnt--;
                l++;
            }
            r++;
        }
        return (sInd == -1)? "" : s.substr(sInd, minLen);
    }
};