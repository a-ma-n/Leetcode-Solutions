class Solution {
public:
    void backtrack(string &s,int i,vector<string>&res){
        if(i==s.size()){
            res.push_back(s);
            return;
        }
        backtrack(s,i+1,res);
        if(isalpha(s[i])){
            /*
            The integer with 6th LSB as 1 is 32 (0010 0000). Therefore, bitwise XORing of a character               with 32 will toggle the 6th LSB of character and hence, will toggle its case. If character i                s upper case, it will be converted to lower case and vice versa. 
            */
            s[i]^=(1<<5);// xor with 32
            backtrack(s,i+1,res);
        }
    }
    
    
    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        backtrack(s,0,res);
        return res;
    }
};