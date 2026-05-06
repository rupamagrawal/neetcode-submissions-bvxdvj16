class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length()-1;

        while(left < right){
            if(s[left] != s[right]){
                return isPal(s, left, right-1) || isPal(s, left+1, right);
            }
            left++;
            right--;
        }
        return true;
    }

    bool isPal(string& s, int left, int right){
        while(left<right){
            if(s[left++] != s[right--])return false;
        }
        return true;
    }
};