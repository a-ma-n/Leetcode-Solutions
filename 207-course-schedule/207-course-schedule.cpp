class Solution {
public:
  bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge : adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
      // if we visit a node twice mark it 2 means a cycle exists
        vis[id] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto edge : pre)//passing the pre requisite
            adj[edge[1]].push_back(edge[0]);// at index of pre req add new element
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i))
                return false;
        }
        return true;
    }
};
