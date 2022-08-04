class Solution {
public:
    int findMin(vector<int>& nums) {
      int start =0,end=nums.size()-1;
        while(start<end){
            int mid = start +(end-start)/2;
            
            // Right side to mid is sorted that means, the min element will be on the left
            if(nums[mid]<nums[end]) 
                end = mid;
            else 
                start =mid+1;      
        }
        // we dont have a condition when the element is eqaual to something since we dont know the target we are after
        // we are simply trying to get a range which is not in the normal order,i.e. increasing in this case which leads us to getting the end index as the index on which our result lies
        return nums[end];
    }
};