class Solution {
public:
    /*
    https://leetcode.com/problems/power-of-four/discuss/482197/C%2B%2B-1-line-code-faster-than-100-(0-ms)-with-explanation-no-loopsrecursion
    */
    bool isPowerOfFour(int &n) {
        //return((n&1)==1 && ((n>>1)&1)==1) ;
        return n>0 && (n&(n-1))==0 && (n&0xAAAAAAAA)==0;
    }
};