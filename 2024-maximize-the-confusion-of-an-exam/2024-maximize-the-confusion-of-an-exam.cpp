class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxF(answerKey,k),maxT(answerKey,k));
    }
    int maxF(string s, int k){
        int i=0, maxi = 0 , j = 0 , N = s.size(),cnt=0;
        for(;j<N;j++){
            if(s[j]=='T') cnt++;
            while(cnt>k)
                if(s[i++]=='T') cnt--;            
            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
    int maxT(string s, int k){
        int i=0, maxi = 0 , j = 0 , N = s.size(),cnt=0;
        for(;j<N;j++){
            if(s[j]=='F') cnt++;
            while(cnt>k)
                if(s[i++]=='F') cnt--;            
            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
    
};