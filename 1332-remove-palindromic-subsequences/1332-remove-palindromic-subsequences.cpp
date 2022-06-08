class Solution {
public:
    int removePalindromeSub(string s) {
    int n = s.length();
    if(n==0)
        return 0;
    for(int i=0, j=n-1;i<n,j>=0;i++,j--)
        if(s[i] != s[j])
            return 2;
    return 1;
    }
};