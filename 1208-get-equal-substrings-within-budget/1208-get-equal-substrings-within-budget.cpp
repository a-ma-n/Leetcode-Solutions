class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0 , j = 0 , N = s.size(), cost = 0, maxi =0;
        for(;j<N;j++){
            cost+=abs(s[j]-t[j]);
            while(cost>maxCost){
                cost-=abs(s[i]-t[i]);
                i++;
            }
            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
};