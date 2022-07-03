class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
       
       vector<int>prev(amount+1,0);
        
        
        int i,j;
        for(i=0;i<=amount;i++)
        {
            if((i%coins[0])==0)
                prev[i]=i/coins[0];
            else
                prev[i]=1e9;
        }
   
        for(i=1;i<n;i++)
        {
            vector<int>curr(amount+1,0);
            for(j=0;j<=amount;j++)
            {
                int notTake=prev[j];
                int take=1e9;
                if(j>=coins[i])
                    take=1+curr[j-coins[i]];
                curr[j]=min(take,notTake);
            }
            prev=curr;
        }
        if(prev[amount]==1e9)
            return -1;
        
        return prev[amount];
        

    }
};