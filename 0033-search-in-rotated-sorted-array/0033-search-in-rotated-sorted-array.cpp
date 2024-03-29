class Solution {
public:
   // 1) find pivot
   // 2) do binary search on the increasing order part after pivot if nums[low]<=nums[mid]
    
    int search(vector<int>& nums, int target) {
        int low =0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[low]<=nums[mid]){ // => this part of the array is sorted apply binary search here
                // b/w low and mid 
                // if target is smaller than mid and target is greater than low
                if(nums[low]<=target && nums[mid]>=target)
                    high = mid-1;
                else
                    low = mid+1;
            }
            // target not in low and mid : on right of mid : low-mid<->high
            else{
                // b/w mid-high
                // target is greater than mid and target is less than high 
                if(nums[mid] <= target && target <=nums[high])
                    low = mid+1;
                else
                    // if there is a peak between mid and low so that target is greater than both high and mid
                    // if target is not in between mid and high => it is on the rotated part 
                    high = mid-1;
            }
        }
        return -1;
        
    }
};


// a-> find 0 , b) then apply bin search on the rest to find other val
        // a) find 0
        // 1) take mid, if nums[mid]==0 return 0,mid-1 is less than mid => search in
        // low=mid+1 if low==0 return low, if high ==0 return high
        // if mid >mid-1


/*/ int n=nums.size(),pos0,shift;
        if(n-1==nums)
        pos0 = bins(0,n-1,target,nums); 
1) search for 0, if target is 0 itself return index , 
        // * edge case => array not rotated -> 0 at 0 index => cant gobackwards -1 doesnt exist
        // 2) if last index of array if taget is > than it then , take low=start->high=0th-1 pos=>apply bin search
        // 3) else apply bin search as , low =mid, high =n-1;
       // ------------------------------------------------------------
 int bins(int low,int high,int t,vector<int>& nums){
        // can also do with recursion
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            else
        }
        // not found
        return -1;
    }*/