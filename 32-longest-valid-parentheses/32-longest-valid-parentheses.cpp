class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stck;
        stck.push(-1);
        int res=0;
        for(int i=0;i<s.length();i++){
            // add ( to the stack
            if(s[i]=='('){
                stck.push(i);
            }
            else{
                // If stack is NOT empty then, means a ( remains => pop that (
                if(!stck.empty())
                    stck.pop();
                // If stack is still not empty => [i-stck.top()] , basically stck.top holds the error index ,
                // Main trick: 
                // lengthx [index - last error index], 
                // max(length1,length2,length3,...)
                if(!stck.empty()){
                    res = max(res,i-stck.top());
                }
                else
                    stck.push(i);
            }
        }
        return res;
    }
};