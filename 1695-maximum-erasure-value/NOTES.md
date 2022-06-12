My approach earlier: (Wrong)
max sum subarray containing unique elements
- sliding window -> if repeat found , store the max score and then slide the window after the duplicate -> shorten the window after the dup again expand the window
- Brute force- recursion? = > find sums of all subarrays with unique elements
- hint -> max => monotonic stack to store max
- nlogn complexity => heap/ bs + linear
​
​
Correct approach:
1 - use unordered sethash
2 - sliding window in such a manner if we encounter repeat element , increment the start
3 - do this till we end up removing the previous duplicate element then simply add the end elements with the sum
​