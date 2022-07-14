class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(auto it:grid){
            count+=bins(it);
            //cout<<count<<endl;
        }
        return count;
    }
    int bins(vector<int>&nums){
        if(nums[0]<0) return nums.size();
        int n=nums.size();      
        int low=0,high=n-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]<0){
                
                //if we found are negative element
                if(nums[mid-1]>=0) return n-mid;
                //there is a negative element before this element
                else high = mid-1;
            }
            else if(nums[mid]>=0) low = mid+1;
                
        }
        return 0;
    }
};