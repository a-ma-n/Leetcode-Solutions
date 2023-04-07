class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph=defaultdict(list)
        for i,j in tickets:
            graph[i].append(j)
        
        for key in graph:
            graph[key].sort(reverse=True)

        visited=set()
        result = []
        
        def dfs(node):
            while graph[node]:
                neigh = graph[node].pop()
                dfs(neigh)
            result.append(node)
        
        dfs("JFK")
        return result[::-1]
