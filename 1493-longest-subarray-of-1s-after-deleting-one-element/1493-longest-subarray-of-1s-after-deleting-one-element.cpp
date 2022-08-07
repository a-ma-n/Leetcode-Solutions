class Solution {
public:
    // both shrinkable and non shrinkable approaches would work as we just need to find the max size of the window, so if we expand the window we will get the max value
    int longestSubarray(vector<int>& A) {
        long i = 0, j = 0, N = A.size(),cnt=0;
        for (; j < N; ++j) {
            cnt+=A[j]==0;
            if(cnt>1) cnt-=A[i++]==0;   
        }
        cout<<i<<" "<<j<<endl;
        return j-i-1;
        /*
        int i = 0, j = 0, N = A.size(), cnt = 0;
        for (; j < N; ++j) {
            cnt += A[j] == 0;
            if (cnt > 1) cnt -= A[i++] == 0;
        }
        return j - i - 1;*/
    }
};