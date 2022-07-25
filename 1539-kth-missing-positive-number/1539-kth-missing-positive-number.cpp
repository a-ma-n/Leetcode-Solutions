class Solution {
public:
    //last index - first - size => integers 
    int findKthPositive(vector<int>& a, int k) {
        int l = 0 , r=a.size(), m;
        while(l<r){
            m=(l+r)/2;
            if(a[m]-1-m<k) l=m+1;
            else r=m;
        }
        return l+k;
        
    }
};
/*
Explanation
Assume the final result is x,
And there are m number not missing in the range of [1, x].
Binary search the m in range [0, A.size()].

If there are m number not missing,
that is A[0], A[1] .. A[m-1],
the number of missing under A[m] is A[m] - 1 - m.

If A[m] - 1 - m < k, m is too small, we update left = m.
If A[m] - 1 - m >= k, m is big enough, we update right = m.

Note that, we exit the while loop, l = r,
which equals to the number of missing number used.
So the Kth positive number will be l + k.


Complexity
Time O(logN)
Space O(1)
*/