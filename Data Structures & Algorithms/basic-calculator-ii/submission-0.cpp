class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        if (len == 0)
            return 0;
        int currN = 0, lastN = 0, res = 0;
        char sign = '+';

        for(int i=0; i<len; i++){
            char currC=s[i];

            if(isdigit(currC)){
                currN = (currN*10) + (currC-'0');
            }
            if((!isdigit(currC) && !isspace(currC)) || i==len-1){
                if(sign == '+' || sign == '-'){
                    res += lastN;
                    lastN = (sign =='+')? currN : -currN;
                }
                else if(sign =='*'){
                    lastN *= currN;
                }
                else if(sign == '/'){
                    lastN /= currN;
                }

                sign = currC;
                currN = 0;
            }
        }

        res += lastN;
        return res;
    }
};