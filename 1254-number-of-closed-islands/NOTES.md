2 approaches:
​
1) make all connected 0s -> 1 and if the connected element gets out of index then dont count it
- need a visited array for this
​
2) **Better approach** We apply dfs on boundary and mark all boundary Os and its connected components as -1(to recognize they are visited). Now,the matrix consists of only those Os that are surrounded by water.So, we perform dfs on the matrix and find the number of connected components.
* mark visited nodes as -1
​