class Solution {
private:
    vector<vector<int>> tree;
    int find(vector<int>&A, int val){
        int low=0;
        int high = A.size()-1;
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(A[mid] < val){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        if(ans == -1){
            return 0;
        }
        else return ans+1;
    }
    void build(int tn, int tl, int tr, vector<int>&A){
        if(tl == tr){
            tree[tn].push_back(A[tl]);
            return ;
        }
        int mid = tl + (tr - tl)/ 2;
        build(tn*2, tl, mid, A);
        build(tn*2 + 1, mid+1, tr, A);
        
        int i=0, j=0;
        while(i < (int)tree[tn*2].size() && j<(int)tree[tn*2+1].size()){
            if(tree[tn*2][i] < tree[tn*2+1][j]){
                tree[tn].push_back(tree[tn*2][i]);
                i++;
            }
            else{
                tree[tn].push_back(tree[tn*2+1][j]);
                j++;
            }
        }
        while(i < (int)tree[tn*2].size()){
            tree[tn].push_back(tree[tn*2][i]);
            i++;
        }
        while(j < (int) tree[tn*2+1].size()){
            tree[tn].push_back(tree[tn*2+1][j]);
            j++;
        }
    }
    int query(int tn,int tl,int tr,int l,int r,int val){
        
        if(l>r) return 0;
        
        if(tl==l & tr ==r) return find(tree[tn],val);
        
        int mid = tl +(tr-tl) /2;
        int a = query(tn*2,tl,mid,l,min(r,mid),val);
        int b = query(tn*2+1,mid+1,tr,max(l,mid+1),r,val);
        return a+b;
    }
    
public:
    vector<int> countSmaller(vector<int>& A) {
        int n = A.size();
        if(n==0){
            return {};
        }
        tree.resize(4*n+4);
        build(1,0,n-1,A);
        vector<int>Ans;
        for(int i =0;i<n;i++){
            int ans;
            ans=query(1, 0, n-1, i, n-1, A[i]);
            Ans.push_back(ans);
        }
        return Ans;
    }
};