class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& A, int k) {
        int i = 0, j = 0, ans = 0,N=A.size(),prod=1;
        for (; j < N; ++j) {
            // CODE: use A[j] to update state which might make the window invalid
            prod*=A[j];
            while (i<=j&&prod>=k)  prod/=A[i++]; // when invalid, keep shrinking the left edge until it's valid again
                // CODE: update state using A[i]
            ans  +=( j - i + 1); // the window [i, j] is the maximum window we've found thus far
        }
        return ans;
    }
};