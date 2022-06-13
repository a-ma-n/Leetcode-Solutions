class Solution {
public:

int max(int i,int j)
{
    return (i > j) ? i : j ;
}
 
string longestCommonPrefix(vector<string>& strs) {
   
    string ans = "", s = strs[0] ;

    int n = strs.size() ;
    int p=0;
    
    for(auto x: strs)
        if(x == ans) p++ ;
    
    int maxi = 0 ;
    for(auto x:strs)
        maxi = max(maxi,x.size()) ;
    
    if(p==n) return ans ;
    
    
    for(int i=0;i<maxi;i++)
    {
        int c=0;
        char t = s[i] ;
        
        for(int j=0;j<n;j++)
            if(strs[j][i] == t) c++ ;
        
        if(c == n) ans += t ;
        else break ;
    }
    
    return ans ;
}
};