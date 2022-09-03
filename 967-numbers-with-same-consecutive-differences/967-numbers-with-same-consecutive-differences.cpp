class Solution {
public:
    void dfs(vector<int> &res,int ans,int n,int k,int length,int i){
        //cout<<"ans "<<ans<<" k "<<k<<" n "<<n<<" length "<<length<<endl;
        if(length>n) return;
        if(length==n) {
            res.push_back(ans);
            return;
        }
        
        
        if(i+k<=9){
            int result=ans*10+abs(i+k);
            dfs(res,result,n,k,length+1,i+k);
        } 
        
        if(i-k>=0 && k!=0){
            int result=ans*10+(i-k);
            dfs(res,result,n,k,length+1,i-k);
        }
        return;
    }
        
    vector<int> numsSameConsecDiff(int n, int k) {
       /*
       1. start with all numbers 
       2. add k , subtract k  and check if its still in the range 0-9 else its not possible
       3. stop it when the iteration = n
       */ 
        vector<int> res;
        for(int i =1 ;i<10;i++)
            dfs(res,i ,n,  k, 1, i);
        return res;
    }
};