class Solution {
public:
    bool isPalindrome(int x) {
        int k=x;
        long rev=0;
        while(k>0){
            rev=rev*10+k%10;
            k/=10;
        }
        return (rev==x)?true:false;
    }
};