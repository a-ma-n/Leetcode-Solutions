class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,mid,n=nums.size(),high=n-1; // nums[n] x => thus we take high=n-1
        
        vector<int>ans(2,-1);
        
        if(n==0) return ans;
        
        while(low<=high){
            mid = low+(high-low)/2;
            if(nums[mid]==target) break; 
            else if(target<nums[mid]) high = mid-1;            
            else low = mid+1;
        }
        // if we found the element
        if(nums[mid]==target){
            
        int firstOccurence =mid;
                while(firstOccurence>=1 && nums[firstOccurence]==nums[firstOccurence-1]){
                   firstOccurence--;
                }
            
         int secondOccurence=mid;
                while(secondOccurence<n-1 &&nums[secondOccurence]==nums[secondOccurence+1]){
                    secondOccurence++;
                }
                ans[0]=firstOccurence;
                ans[1]=secondOccurence;
        }
        
        return ans;
    }
};