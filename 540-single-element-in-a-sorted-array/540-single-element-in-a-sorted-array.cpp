class Solution {
public:
    // 1) find the mid, if same element on right shift mid one right
    // 2) find left and right length, if left length odd high=mid-1 else low=mid+1
    // 3) repeat till we have no adjacent element on both side, ie left ,mid(wherever its adj element lies) == rigth
    
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0,n=nums.size(), high=n-1,mid ;
        
        if(n==1)
            return nums[0];
        
        while(low<=high){
            mid = (low+high)/2;
            if(mid==0 || mid==n-1)
                break;
            if(nums[mid]==nums[mid-1]){
                // if start length is odd then take high =mid-1 => we search start portion
                if((mid-low+1)%2!=0){
                    high=mid;
                }
                // start length even
                else{
                    low=mid+1;
                }
            }
            else if (nums[mid]==nums[mid+1]){
                //
                if(((mid-1)-low+1)%2!=0){
                    high=mid-1;
                }
                else{
                    low=mid;
                }
            }
            else{
                break;
            }
        }
       return nums[mid];
    }
};