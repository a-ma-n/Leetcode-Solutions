class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0],maxSum=sum,i,n=nums.size();
        for( i = 1 ;  i < n ; i ++){
            if(sum<0){
                //maxSum=max(maxSum,sum);
                sum=0;
            }
            sum+=nums[i];
           maxSum=max(maxSum,sum);  
        }
        maxSum=max(maxSum,sum);
        return maxSum;
    }
};