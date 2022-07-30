class Solution {
public:
    // at the end we must reach the recursive length so that rooms.size() == our recursive depth => return true
    // else return false
    
    void dfs(vector<vector<int>>& rooms,vector<bool>& visited,int i){
      visited[i]=true;
       for(auto& room:rooms[i]) 
           if(!visited[room]) dfs(rooms,visited,room);    
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        dfs(rooms,visited,0);
        for(auto v:visited) if(!v) return false;
        return true;
    }
};