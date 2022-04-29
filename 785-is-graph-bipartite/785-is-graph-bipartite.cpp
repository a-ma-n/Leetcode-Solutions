class Solution {
public:
   // BFS
/*
    bool bipartiteBFS(int src,vector<vector<int>>& graph,int color[]){
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    */
    
    bool bipartiteDFS(int node,vector<vector<int>>& graph,int color[]){
        
        if(color[node]==-1) color[node] =1;
        
        for(auto it: graph[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                if(!bipartiteDFS(it,graph,color)) {
                    return false;
                }
            } else if(color[it] == color[node]) return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        
        int n =graph.size();
        int color[n];
        memset(color,-1,sizeof color);
        for(int i =0; i<n;i++){
            if(color[i]==-1){
                // BFS
               // if(!bipartiteBFS(i,graph,color))
              //    return false;
                // DFS
                if(!bipartiteDFS(i,graph,color))
                     return false;
            }
        }
        return true;
    }
};