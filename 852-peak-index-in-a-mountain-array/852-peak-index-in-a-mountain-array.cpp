class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size(),low=0,high=n-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            //cout<<low<<" "<<mid<<" "<<high<<endl;
            // given condition
            if( (mid>0 && arr[mid]>arr[mid-1])
                &&
               (mid<n-1 && arr[mid]>arr[mid+1])
              ){
                return mid;
            }
            // decreasing => go left
            else if(mid > 0 && arr[mid]<arr[mid-1]) high = mid-1;
            else if(mid==0) low=mid+1;
            else if(mid==n-1) high=mid-1;
                
                
            // increasing => go right
            else low = mid+1;
            
        }
        return mid;
    }
};