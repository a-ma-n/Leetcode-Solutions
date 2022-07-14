[4,3,2,-1]
[3,2,1,-1]
[1,1,-1,-2]
[-1,-1,-2,-3]
​
mxnlogn => 10^4log100
​
- if prev element is +ive and current element is -ive -> all ele to right including itself is -ive
​
edge cases:
1) if we are taking the 1st element then the index:-1 does not exist => so check if mid==0 & nums[mid]<0 => count+=nums[i].size()