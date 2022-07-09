class Solution {
public:
    bool ip(int n){
        if(n==2) return true; // 16->8->4->2->1
        if(n%2==1) return false;// 3)->1 -> 1, 5-
        return ip(n/2);
    }
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n==0 ||n<0) return false;
        return ip(n);
    }
};