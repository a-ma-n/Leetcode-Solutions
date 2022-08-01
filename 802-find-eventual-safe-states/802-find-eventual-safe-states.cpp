class Solution {
public:
    // 5,6 -> terminal node
    // get all states directing to terminal nodes
    
    // Return false when cycle is found
    bool dfs(int source,vector<bool>& visited,vector<bool>&currVisited,vector<vector<int>>& graph,vector<bool> &safe){
        visited[source] = true;
        currVisited[source] = true;
        
        // Explore adj vertices
        for(auto adj:graph[source] ){
            
            if(visited[adj]==false){// unvisited node
                // if cycle exists w.r.t adj vertex then false is returned
                if( dfs( adj,visited,currVisited,graph,safe) == false )
                    return safe[source]=false;
            }
            // if the vertex is visited already and it is currently in the previous DFS calls 
            else if(visited[adj]==true && currVisited[adj]==true){
                // Cycle exists
			    // Hence cannot reach terminal node thus return false
                return safe[source] = false;
                
            }
            
        }
      
        // As adj vertices of source are explored, make currVisited as false because we are coming out of its DFS call
        currVisited[source]= false;
        return safe[source];
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int vertices = graph.size();
        
        // visited stores true for all the vertices that are visited 
	    vector<bool> visited(vertices, false);
        
        // currentVisited stores true for the vertices that are currently in DFS call
	    vector<bool> currVisited(vertices, false);
        
        // Intially, all vertices are considered as safe nodes
	    vector<bool> safe(vertices, true);
        
        for(int i =0;i<vertices;i++){
            if(visited[i]==false)
                dfs(i,visited,currVisited,graph,safe);
        }
        
        vector<int> ans;
        for(int i =0;i<vertices;i++){
            if(safe[i]) ans.push_back(i);
        }
        return ans;
        
    }
};