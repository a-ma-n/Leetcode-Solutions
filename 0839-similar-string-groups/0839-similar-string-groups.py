class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        # Function to check if two strings a and b are similar (neighbors)
        def areNeighbors(a,b):
            dif = 0
            for i in range(len(a)): # Loop through characters in strings
                if a[i]!=b[i]: # Compare characters at the same position
                    dif += 1 # Increase the difference counter if characters are not equal
            return dif==0 or dif==2 # Strings are similar if they are identical or only two characters are different

        # Create a dictionary to represent the graph
        graph = defaultdict(list)
        # Fill the graph. Each string is a node, and its neighbors are the strings similar to it
        for i in range(len(strs)):
            for j in range(i+1,len(strs)):
                if areNeighbors(strs[i],strs[j]):
                    graph[strs[i]].append(strs[j])
                    graph[strs[j]].append(strs[i])

        # Depth-First Search (DFS) function to traverse the graph
        def dfs(node):
            for nei in graph[node]: # Loop through the neighbors of the current node
                if nei not in visited: # If the neighbor has not been visited yet
                    visited.add(nei) # Mark it as visited
                    dfs(nei) # Start a DFS from the neighbor

        visited = set() # Set to keep track of visited nodes (strings)
        res = 0 # Counter for the number of groups
        for i in range(len(strs)): # Loop through the input strings
            if strs[i] not in visited: # If a string has not been visited yet
                visited.add(strs[i]) # Mark it as visited
                dfs(strs[i]) # Start a DFS from it
                res += 1 # Increase the group counter

        return res # Return the number of groups
