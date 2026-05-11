class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        int s1Count[26] = {0};
        int s2Count[26] = {0};

        // build first window
        for(int i = 0; i < s1.length(); i++){
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // count initial matches
        int matches = 0;
        for(int i = 0; i < 26; i++)
            if(s1Count[i] == s2Count[i]) matches++;

        // slide
        int l = 0;
        for(int r = s1.length(); r < s2.length(); r++){
            if(matches == 26) return true;

            // ADD right char
            int add = s2[r] - 'a';
            if(s2Count[add] == s1Count[add]) matches--;     // breaking match
            s2Count[add]++;
            if(s2Count[add] == s1Count[add]) matches++;     // making match

            // REMOVE left char
            int rem = s2[l] - 'a';
            if(s2Count[rem] == s1Count[rem]) matches--;     // breaking match
            s2Count[rem]--;
            if(s2Count[rem] == s1Count[rem]) matches++;     // making match

            l++;
        }

        return matches == 26;
    }
};