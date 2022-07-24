class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 0,high=num,mid,sq;
        while(low<=high){
            mid = low + (high-low)/2;
            sq=mid*mid;
            if(sq==num) return true;
            else if(sq<num) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};