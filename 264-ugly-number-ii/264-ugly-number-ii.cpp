class Solution {
public:
    int nthUglyNumber(int n) {
        
        // since the count of the numbers to be added is upto n,the vector will contain max n numbers
        vector<int> ans(n);
        
        // x=> pointer to index to which 2 will be multiplied
        // y=> pointer to index to which 3 will be multiplied
        // z=> pointer to index to which 5 will be multiplied
        
        // all x,y,z pointers will start multiplication from the oth index
        int x=0,y=0,z=0;
        ans[0]=1;
        for(int i =1;i<n;i++){
            ans[i]=min(ans[x]*2,min(ans[y]*3,ans[z]*5));
            if(ans[i]==2*ans[x])x++;
            if(ans[i]==3*ans[y])y++;
            if(ans[i]==5*ans[z])z++;
            // when ans == value to which more than one pointers among (x,y,z) point, all pointers get increamented
        }
        return ans[n-1];
    }
};