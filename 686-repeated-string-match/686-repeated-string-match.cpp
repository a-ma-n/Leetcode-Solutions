class Solution {
public: 
    
    // s1 -> text string 
    // s2 -> pattern string
    // Check pattern find in text or not !!
    // Rolling hash : hash calculation in sliding window, window moves by 1 step in right  
    int Rabin_Karp(string s1, string s2) 
    {
        long long m=s1.size();
        long long n=s2.size();
        
        long long p = 31;
        long long pow = 1;
        long long mod = 1e9+7;
        long long targetHashVal = 0;
        
        // targetHashVal - calculate hash value of pattern
        for(long long i=0;i<n;i++){
            targetHashVal = (targetHashVal + (s2[i]-'a'+1)*pow)%mod;
            pow = (pow*p)%mod;
        }
        
        // Rabin-Karp algo :
        // prefix hash array
        vector<long long>pha(m);
        // power array : so that my time is not wasting in calculating big powers
        vector<long long>pa(m);
        
        pha[0] = s1[0]-'a'+1;
        pa[0] = 1;
        pow = p;
        
        for(long long i=1;i<m;i++){
            pha[i] = (pha[i-1] + (s1[i]-'a'+1)*pow)%mod;
            pa[i] = pow;
            pow = (pow*p)%mod;
        }
        
        //Now Start sliding window
        // initialize variables for the starting and ending points of window
        long long sp = 0, ep = n-1;
        
        while(ep < m)
        {
            long long win = pha[ep];
            if(sp>0)
                win = (win - pha[sp-1]+mod)%mod; // agar value negative hoti hai toh usme bas mod add kardo
            
            if(win == (targetHashVal*pa[sp])%mod){
                return 1;
            }
            sp++,ep++;
        }
        return 0;
    }
    
    int repeatedStringMatch(string A, string B) 
    {
        // edge cases
        if(A == B) return 1;
        
        int count = 1;
        string source = A;
        while(source.size() < B.size()){
            source+=A;
            count++;
        }
        
        // edge cases
        if(source == B) 
            return count;
        
        if(Rabin_Karp(source,B) == 1) 
            return count;
        
        if(Rabin_Karp(source+A,B) == 1) 
            return count+1;
        return -1;
    }
};
