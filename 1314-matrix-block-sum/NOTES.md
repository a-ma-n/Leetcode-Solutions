we need to calculat sum uptil k elements **up/ down / right/left / diagonal**
- possibly all combinations
- given (r,c) is a valid position in a matrix
- brute force? loop at every position and add the elements there + boundary checks
​
Questions:
- at every point we are calculating the sum of nearby elements and then we are able to store it in the matrix
- should we apply dp? **is there any thing repeated?**
**- prefix sum ?**
- seems like a prefix sum problem where we can find the other values of consecutive elements summing up.
- eg 1 prefix array:
[1  ,  3 , 6  ]
[5  , 13, 25]
[12 ,33, 67] X
we also need to add the diagonals values to get our result
​
​
​
Good illustration , why we need prefix sum here.
[https://leetcode.com/problems/matrix-block-sum/discuss/549010/C%2B%2B-oror-64.38-time-oror-100.00-space-oror-graph-illustration](http://)
​
​
why we use 1d prefix sum and why not 2d prefix sum??