class Solution {
public:
bool makesquare(vector<int>& matchsticks) //Using BITMASKING
{
    int n=matchsticks.size();
    int sum=0;
    
    for(int i=0;i<n;i++)
    {
        sum=sum+matchsticks[i];
    }
    if(n<4 or sum%4 !=0)//when the size of array is less than 4 we are not able to make square and also when the sum is not divisible by 4
        return false;
    
    int target=sum/4;
    vector<int> dp((1<<n),-1);//create dp table of size 2^n size
    dp[0]=0;//start index
    
    for(int mask=0;mask<(1<<n);mask++)
    {
        if(dp[mask]==-1)// Invalid Case
            continue;
        
        for(int j=0;j<n;j++)
        {
            if(!(mask &(1<<j)) && dp[mask]+matchsticks[j]<=target)
            {
                dp[mask | (1<<j)]=(dp[mask]+matchsticks[j])%target;
            }
        }
    }
    return dp[(1<<n)-1]==0?true:false;
}
};