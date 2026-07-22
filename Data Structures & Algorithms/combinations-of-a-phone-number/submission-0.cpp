class Solution {
private:
    void fun(int ind, string s, vector<string>&ans, string combos[], string&digits ){
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }

        int num = digits[ind]-'0';

        for(char ch: combos[num]){
            fun(ind+1, s+ch, ans, combos, digits);
        }
    }


public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        string combos[] = {"", "", "abc", "def",  "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string s="";
        vector<string>ans;

        fun(0, s, ans, combos, digits);
        return ans;
    }
};
