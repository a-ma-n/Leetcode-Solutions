class Solution {
public:
    int minOperations(vector<int>& A) {
        int i =0, j=0 , ans =0 ,N = A.size();
        sort(A.begin(),A.end());
        // we are erasing all the duplicated elements
        A.erase(unique(A.begin(),A.end()),A.end()); // only keep unique elements
        for(int M = A.size();j<M;j++){
            // while => ( A[j] - A[i] ) >= N => move i ahead, so window shortens and the value of window reduces
            while(A[i]+N<=A[j]) ++i;
            ans = max(ans,j-i+1);
            
        }
        // this window has the size such that => max-min (window size) = nums.size-1
        // now the number of elements to be changed => elements in the array - size of sliding window ()
        return N - ans; 
    }
};