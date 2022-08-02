/*
Complexity Analysis

Time: O(m), where m is the number of connections (union operations) or (alpha*m) here alpha can be considered to be constant as we are doing path compression.
Memory: O(n+n) = O(n) for the disjoint set.
*/

class Solution {
public:
    // cannot make a MST as we need to return the min no. of changes
    // take count of edges of already connected components 
    // number of connections needed ?
    // if the number of wires we have < number of connections needed => -1
    vector<int> parent;
    vector<int> rank;
    
    // finding the parent of the node u
    int findPar(int u){
        if(parent[u]==u) return u;
        return parent[u]=findPar(parent[u]); //path compresssion, storing the computed value;
    }
    void unionn(int u,int v){
        u = findPar(u);
        v = findPar(v);
        
        // smaller rank guy gets attacehd to higher rank guy
        // only same rank -> increase any one's rank
        if(rank[u]<rank[v])
            parent[u]=v; // smaller rank is u and parent is v
        else if(rank[v]<rank[u])
            parent[v]=u; // smaller rank is v and parent is u
        else{ // level only increases when we are attaching 2 similar guys
            parent[v]=u;
            rank[v]++;
        }
    }
        
    int makeConnected(int n, vector<vector<int>>& conn) {
       
        if(conn.size()<n-1) return -1; // to combine n computer we require n-1 wires but here it's not the case
     
        // filling parent and rank array
        for(int i =0;i<n;i++)
            parent.push_back(i),rank.push_back(0);
        
        // iterating to connection array and connecting them
        for(auto& it : conn)
            unionn(it[0],it[1]);
        
        // counting the nnumber fo different components
        int differentComponents = 0 ;
        for(int i =0;i<n;i++)
            if(parent[i]==i) differentComponents++; // parentComponent[i]==i         => new componenet 
        //total {DifferentComponents} components are there and we need to join them in mininimum cable 
        //so best way to join them will be linearly( think ) which will require DifferentComponents-1 cables only;
        
        return differentComponents-1;    
    }
};