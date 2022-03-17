class Solution {
public:
    string interpret(string command) {
        string res="";
        string s=command;
        int i;
        for( i=0;i<command.length()-1;i++){
            if(s[i]=='G'){
                res=res+s[i];
            }
            if(s[i]=='(' && s[i+1]==')'){
                res=res+"o";
                i++;
            }
            if(s[i]=='(' && s[i+1]=='a'){
                res=res+"al";
                i=i+3;
            }
        }
        //cout<<s.length()<<endl;
        cout<<i<<endl;
        if(s[i]=='G')
            res=res+"G";
        return res;
        
    }
};