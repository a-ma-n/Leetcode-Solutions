class Solution {
public:
    // return total number of subgraphs
    // total number of grpahs = length of the is connected array
    // maintain a visited array -> to keep track of visited nodes
    // iterate throught the visited arry and see if there is any node not yet visited then increase  the count and start dfs again
    
    void dfs(vector<vector<int>>& graph,vector<bool>& vis,int i=0){     
        vis[i]=true; // visited
        for(int j=0;j<graph.size();j++) 
            if(graph[i][j]==1 && !vis[j]) // if the componenet is marked as connected and is not visited then do dfs on this part of the graph
                dfs(graph,vis,j);
        
    }
    
    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size(),ans=0;
        vector<bool> vis(n,false);
        if(n==0) return 0;
        
        for(int i=0;i<n;i++) {
            if(!vis[i]){
                ans++;
                dfs(graph,vis,i);
            }
        }
        return ans;
        
    }
};