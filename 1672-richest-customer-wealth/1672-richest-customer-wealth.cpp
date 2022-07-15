class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum=0,maxm=0;
        for(auto it:accounts){
            sum=0;
            for(auto i:it)
                sum+=i;
            maxm=max(maxm,sum);
        }
        return maxm;
    }
};