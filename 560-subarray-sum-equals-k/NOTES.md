k = 15
nums = [1, -5, 20]
sum = 1, -4, 16
​
subarray [-5, 20] is the answer
cumulative sum is 16 here, so the answer is produced by subtracting one subarray from another:
[1, -5, 20] // sum is 16
[1] // sum is 1
sum([1, -5, 20]) - sum([1]) = sum([-5, 20]) = 15
​
And that's how we find the answer, by finding previous sums [0 .. L] that are equal to sum - k, to subtract [0 .. R] - [0 .. L] and get [L .. R] with sum = k.
​
BUT
How do we detect subarrays with sum equal k and starting with 0 index?
By subtracting empty array, e.g. k = 6, nums = [1, 2, 3], the answer is sum([1, 2, 3]) - sum([]) = sum([1, 2, 3]) = 6
​
And how do we find that empty array?
We fill the prefix map first with mp[0] = 1, knowing we have one virtual subarray (in which no elements from nums are included), which we "find" when our cumulative sum is the answer itself and no need to subtract something.