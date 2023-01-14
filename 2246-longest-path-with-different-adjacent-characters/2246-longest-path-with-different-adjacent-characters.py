class Solution:
     def longestPath(self, parent, s):
        #creating a tree
        children = [[] for i in range(len(s))]
        for i,j in enumerate(parent):
            if j >= 0:
                children[j].append(i)
        # use list in res so theres no issue of local and nonlocal and even if we edit res inside the fn we will see the reflected changes outside
        res = [0]
        def dfs(i):
            candi = [0]
            for j in children[i]:
                cur = dfs(j) # stores the cur path length
                if s[i] != s[j]:
                    candi.append(cur)#append the current length which we could get as a possible length
            candi = nlargest(2, candi) # get the 2 largest paths in candi
            res[0] = max(res[0], sum(candi) + 1)# compare if the added paths (its the path from 2 leaf nodes to current nodes +1 gives us max path compared to the max path we had earlier)
            # return the max path we got till now to 2 leaves and add 1 for current node
            return max(candi) + 1
        
        dfs(0)
        return res[0]
        