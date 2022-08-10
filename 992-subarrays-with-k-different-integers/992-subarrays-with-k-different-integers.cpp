class Solution {
public:
    /*
    If you're given an array of length n, it will produce (n *(n+1))/2 total contiguous subarrays (same as doing the sum above).
    This is used often in other questions where we know our array size of n and so we don't need to add [1...n] incrementally like this problem.
*/
    int atmost(vector<int>& A, int k){
        
        if (k < 0)return 0;
        
        int i = 0 , j = 0 , res = 0,N = A.size() ; 
        unordered_map<int,int>count;
        
        for(;j<N;j++){
            
            // if count A[j]==0 => we have a new integer , => subtract k as we have a new different integer
            if (!count[A[j]]++) k--;
            
            // if say k < 0 = > 
            while(k<0) {
                // decrease the count of eleemnt at i, as we are moving the i index by 1 => increment k(when the count of that number is 0) => do this till we see that the value of k is greater than 0
                if(!--count[A[i++]]) k++;
            }
            // this concept of length of an array gives n*(n+1)/2 subarrays is used over here and we store the size of the window over here for the same ; Basically we are adding up the window sizes
            res+=j-i+1;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // this concept will come to our mind when we are looking at sliding window problems,as in sliding window we usually find the aggregate of a quantity 
        // What we are doing is: 
        // exactly(K) = atMost(K) - atMost(K-1)
        return atmost(nums,k) - atmost(nums,k-1);
    }
};