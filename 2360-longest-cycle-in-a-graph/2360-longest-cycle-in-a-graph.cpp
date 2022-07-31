class Solution {
public:
    int maxLength = -1;

    void getcycle(vector<int> &edges,int si,vector<bool>& visit,int size,vector<int>& store){
        if(si==-1) return;
        if(visit[si]){
            int count =-1;
            for(int i = 0 ; i<store.size();i++){
                if(store[i]==si){
                    count = i;
                    break;
                }
            }
            if(count==-1)return;
            maxLength=max(maxLength,size-count);
            return;
        }
        visit[si]=true;
        store.push_back(si);
        getcycle(edges,edges[si],visit,size+1,store);
        return;
    }
    
    
    
    int longestCycle(vector<int>& e) {
        int n = e.size();
        vector<bool> visit(n,0);
        for(int i =0;i<n;i++){
            if(visit[i]) continue;
            vector<int> store;
            getcycle(e,i,visit,0,store);
        }
        return maxLength;
    }
};