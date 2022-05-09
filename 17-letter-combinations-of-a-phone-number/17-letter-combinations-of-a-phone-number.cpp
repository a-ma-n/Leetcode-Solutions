class Solution {
public:
    
    
    vector<string> letterCombinations(string digits) {
        
        // 0,1,---
        vector<string> v={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string> res;
        if(digits.size()==0)
       {
           return res;
       }
       res.push_back(""); //0 -> blank
        
       for(int k=0;k<digits.length();k++)
        {
            vector<string> temp;
           // store the value of the strings at the indexe -> abc , def, ghi ...
            string s = v[digits[k] - '0'];   


            for(int i=0;i<s.length();i++) // iterate through the string ->once 
            {
                for(int j=0;j<res.size();j++) // iterate through the string ->again 
                {
                    // temp stores the temporary concatenaition og the string and then add the other 
                    // characters towards the right 
                     temp.push_back(res[j]+s[i]);
                }
            }
               swap(temp,res);
       }
        
        return res;
    }
};