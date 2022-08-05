class Solution {
public:
    // each time for n unique characters the number of substrings going forward is n
    // LEETCODE
    //   ^   ^
    //   E,ET,ETC,ETCO,ETCOD => 5 combinations  
    int cur[26],prev[26]; // occurences. at first 0, so I'll use 1-based indexing
    int uniqueLetterString(string s) {
        int i,n=s.size();
        long long total = 0LL;
        char ch;
        /*
        prev-cur-next  => trio of indexes of char ch
        in how many substrings will ch with position cur will be unique
        potential starting points are => [prev+1,cur] & [cur,next-1]
        so each time total += (cur - prev)*(next-cur)
        */
        for(int i = 1 ; i <= n ; i ++ ){
            ch = s[i-1] -'A';
            total += (cur[ch]-prev[ch])*(i-cur[ch]);
            prev[ch]=cur[ch];
            cur[ch]=i;
        }
        // haven't counted last occurences yet. so IMAGINE each letter pushed-back to string s
        for(ch=0;ch<26;ch++) total+=(cur[ch]-prev[ch])*(n+1-cur[ch]);
        return total;
    }
};