// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    // true true false false false
    // need to find the first false version
    int firstBadVersion(int n) {
        int low =0,high= n,mid;
        while(low<high){
            mid = low+ (high-low)/2;
            if(isBadVersion(mid) && !isBadVersion(mid-1)){
                return mid;
            }
            else if(!isBadVersion(mid)) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};