class Solution {
public:
    // return max smallest triangle we can form with the givne coins
    // n(n+1)/2 <= n  
    // => left is smaller than n & right is greater than n
    
    // ap sum + last row => 1+2+...n+n = n(n+1)/2 + n = total coins ; n =?
    int arrangeCoins(int n) {
        long low=0,high=n,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if( mid*(mid+1)/2 == n  ) return mid;
            else if(mid*(mid+1)/2 > n) high=mid-1;
            else low = mid+1;
        }
        return low-1;
    }
};