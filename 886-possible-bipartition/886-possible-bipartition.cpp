class Solution {
public:
    // BFS
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // mapped index->disliked indexes
        vector<int> graph[n+1]; // is this adjacency list??
        for(auto &d: dislikes){
            graph[d[0]].push_back(d[1]); // there can be 
            graph[d[1]].push_back(d[0]);
        }
        
        vector<int> color(n+1,0);
        
        // this will execute for alternate nodes where color = 1 
        for(int i =1;i<=n;i++){
            if(color[i]!=0)
                continue;
        
            color[i]=1;
            queue<int> q;
            q.push(i);
        
        // bfs logic
        
            while(!q.empty()){
                int node = q.front();
                q.pop();
                // v is the disliked graph node, of all the disliked nodes
                for(auto&v:graph[node]){
                    if(color[v]==0){
                        color[v]=3-color[node];
                        q.push(v);
                    }
                    else if(color[v]==color[node]){
                        return false;
                    }
                }
            }
        }
    return true;
    }
};