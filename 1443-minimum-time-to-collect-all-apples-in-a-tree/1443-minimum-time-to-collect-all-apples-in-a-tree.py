class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        seen, g = set(), defaultdict(list)

        for a,b in edges: 
            g[a].append((b)) 
            g[b].append((a))
        def dfs(node: int)->int:
            seen.add(node)    
            ans = sum(dfs(n) for n in g[node] if n not in seen) 
            if not ans and not hasApple[node]:
                return 0
            print(node,ans+2)
            return ans+2           

        return max (0,dfs(0)-2) # subtract 2 for our last node , i.e. our answer