int rob(vector<int>& nums) {
int n = nums.size();
memset(dp, -1, sizeof dp);
//todo check how would i declare it if it were a 2d vector array
return rec(nums,0,false);
}
```
**Tabulation**
- 2 dp, indexing starts from 0 &
- in dp we include the first element
- in dp1 we dont include the first element
```
int rob(vector<int>& nums) {
int n = nums.size();
int dp[n+1],dp1[n+1];
dp[0]=0;
dp[1]=nums[0];
dp1[0]=0;
dp1[1]=0;
for(int i =2;i<=n;i++){
if(i==n) dp[i]=dp[i-1];// exclude the last element
else dp[i]=max(dp[i-1],dp[i-2]+nums[i-1]);
dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i-1]);
}
return max(dp[n],dp1[n]);
}
```
​