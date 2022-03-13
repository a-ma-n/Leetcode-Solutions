class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;i<s.size();i++){
            if( s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk.push(s[i]);
            }
            if( s[i] == ')' || s[i] == '}' || s[i] == ']' )
            {
                if (stk.empty()){
                    return false;
                }
                char temp = stk.top();
                stk.pop();
                if(s[i] == ')' &&  temp != '(')
                     return false;
                if(s[i] == '}' &&  temp != '{')
                     return false;
                if(s[i] == ']' &&  temp != '[')
                     return false;
            }
        }
        if (stk.empty())
            return true;
        else 
            return false;
    }
};