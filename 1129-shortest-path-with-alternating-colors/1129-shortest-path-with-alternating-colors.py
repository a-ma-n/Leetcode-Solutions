class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        bAdj=defaultdict(list)
        rAdj=defaultdict(list)
        # n=len(redEdges)
        
        for edge in redEdges: rAdj[edge[0]].append(edge[1])
        for edge in blueEdges: bAdj[edge[0]].append(edge[1])
            
        queue=collections.deque()
        res=[[float(inf),float(inf)] for i in range(n)]
        res[0]=[0,0]
        # 1=> blue, -1 => red
        queue.appendleft([0,-1])
        queue.appendleft([0,1])
        
        currDist=0
        
        while queue:
            queueSize=len(queue)
            
            for i in range(queueSize):
                node,edge=queue[-1]
                queue.pop()
                
                if edge==1: # blue
                    for x in rAdj[node]:
                        if res[x][1]>currDist+1:
                            queue.appendleft([x,-1])
                            res[x][1]=currDist+1
                else:
                    for x in bAdj[node]:
                        if res[x][0]>currDist+1:
                            queue.appendleft([x,1])
                            res[x][0]=currDist+1 
            currDist+=1
                
                
        ans=[0]*n
        print(n,ans)
        for i in range(n):
            mini=min(res[i][0],res[i][1])
            if (mini==float(inf)):
                ans[i]=-1
            else:
                ans[i]=mini
        
        return ans;
                    
        return [0]
        