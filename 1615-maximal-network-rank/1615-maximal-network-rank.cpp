class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        int maximal = 0 ;
        
        // Building the graph(adjaceny list)
        for(const auto &road:roads){
            // using & in loop variable makes it faster to loop 
            graph[road[0]].insert(road[1]);
            graph[road[1]].insert(road[0]);
        }
        
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n;j++){
                
                
                    // Sum of neighbours (connected citizens of both cities)
                    int network_rank = graph[i].size() + graph[j].size();

                    // Reduce the rank by 1 in case cities are connected to each other 
                    if(graph[j].count(i)){
                        // Removing common elements 
                        network_rank--;
                    }
                
                 // Maximal network rank is the max network rank possible
        maximal = max(maximal,network_rank);
        
            }
        }
       return maximal;
    }
};