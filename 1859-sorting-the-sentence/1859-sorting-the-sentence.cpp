class Solution {
public:
    string sortSentence(string s) {
        s=s+" ";
        map <int,string> mp;
        int i=0;
        int p=0;
        string w="";
        for(i=0;i<s.length();i++){
            if(s[i]==' '){
                // i=4 
               // if()
                w=s.substr(p,(i-p)-1);
                    //key= word
                mp[s[i-1]]=w;
                p=i+1;
            }
        }
        string res="";
        
        for(auto it:mp){
            res=res+it.second+" ";
        }
        res=res.substr(0,res.length()-1);
        cout<<res;
        return res;
    }
};