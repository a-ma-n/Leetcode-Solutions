class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 98-122
       int i = 0 , j = 0 , N = s.size(),ans=0,cnt[128]={};
       for (; j < N; ++j) {
            cnt[s[j]]++;
             while (cnt[s[j]] > 1) cnt[s[i++]]--;
           // window will be of size j-i+1
            ans = max(ans, j - i + 1);
        }
        return ans;
        
        
        
    }
};