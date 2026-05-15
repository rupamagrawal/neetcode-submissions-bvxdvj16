class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int op=0;
        int n =s.length();

        for(int i=0; i<n; i++){
            if(s[i] == '(')op++;
            else if(s[i] == ')'){
                if(op==0)s[i] = '*';
                else op--;
            }
        }

        for(int i=n-1; i>=0; i--){
            if(op>0 && s[i] == '('){
                s[i] = '*';
                op--;
            }
        }

        string res="";

        for(int i=0; i<n; i++){
            if(s[i] != '*')res += s[i];
        }

        return res;
    }
};
