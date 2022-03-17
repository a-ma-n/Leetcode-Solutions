class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0,bal=0;
        bool start=true;
        int n=s.length();
        
        //int size=0,maxS=0;
        for(int i=0;i<n;i++){
            
            if(s[i]=='L')
              bal++;
            if(s[i]=='R')
              bal--;
            if(bal==0 && start==false)
                ans++;
            start=false;
            
            
        }
        return ans;
    }
};