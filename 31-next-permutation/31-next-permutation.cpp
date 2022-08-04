class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j,n=nums.size(),tmp=0;
        
        for( i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        if(i<0) reverse(nums.begin(),nums.end());
        else{
            for( j = n-1;j>i;j--){
                if(nums[j]>nums[i]){
                    break;
                }
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }
        //cout<<i<<" "<<j<<endl;
    }
};