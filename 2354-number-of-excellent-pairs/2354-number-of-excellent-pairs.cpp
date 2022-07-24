class Solution {
    /*
    Intuition
    The Inclusion-Exclusion Principle
    bits(num1 OR num2) + bits(num1 AND num2) = bits(num1) + bits(num2)


    Explanation
    For all different a in nums,
    counts its number of bits.

    Enumearte the number of bits k1 and k2,
    if k1 + k2 >= k,
    we accumulate count[k1] * count[k2].


    Complexity
    Time O(nlogn)
    Space O(n)
*/
public:
    long long countExcellentPairs(vector<int>& A, int k) {
        // 2^30 ~10^15 
        
        // initial value of cnt[0] ??
        
        long long cnt[30] = {}, res = 0;
        
        
        for (int a : unordered_set<int>(begin(A), end(A)))
            ++cnt[__builtin_popcount(a)]; // __builtin_popcount -> __builtin_popcount(x) is a function in C++ returns the number of 1-bits set in an int x
        
        // we are iterating thruogh different number of bits and then setting res+=cmt[i]*cnt[j]
        for (int i = 1; i < 30; ++i)
            for (int j = 1; j < 30; ++j)
                if (i + j >= k)
                    res += cnt[i] * cnt[j];
        return res;
    }
};