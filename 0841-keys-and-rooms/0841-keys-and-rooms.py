class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited=[False]*len(rooms)
        stack=[0]
        while stack:
            curr = stack.pop()
            if visited[curr]: continue
            visited[curr]=True
            stack.extend(rooms[curr])
        return min(visited) 