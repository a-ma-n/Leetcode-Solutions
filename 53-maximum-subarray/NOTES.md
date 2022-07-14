**Kadanes algorithm**
```
int maxSubArray(vector<int>& nums) {
int sum=0,maxSum=nums[0];
for(auto it:nums){
sum+=it;
maxSum=max(maxSum,sum);
if(sum<0){
sum=0;
}
}
return maxSum;
}
```
**DP**
**My not working soln**
```
int recur(vector<int>nums,int i,int sum){
if(i==nums.size()-1) return sum+nums[i];
int pick=0,notPick=0;
pick = recur(nums,i+1,sum+nums[i]);
notPick = recur(nums,i+1,0);
return max(pick,notPick);
}
int maxSubArray(vector<int>& nums) {
if(nums.size()==1) return nums[0];
return recur(nums,0,0);
}
```
**Working top down soln**
​