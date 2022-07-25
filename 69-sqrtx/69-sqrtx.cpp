class Solution {
public:
    // insert+square
    int mySqrt(int x) {
       long long low = 0 , high = x,mid;
        while(low<=high){
            mid = low+(high-low)/2;
            //cout<<low<<" "<<mid<<" "<<high<<endl;
            if(mid*mid==x) return mid;
            else if(mid*mid<x) low=mid+1;
            else high = mid-1;
        }
        //cout<<low<<" "<<mid<<" "<<high<<endl;
        return high;
        
    }
};