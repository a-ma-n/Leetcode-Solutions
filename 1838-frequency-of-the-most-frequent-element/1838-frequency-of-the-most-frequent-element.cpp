class Solution {
public:
    int maxFrequency(vector<int>& A, int k) {
        //Shrinkable Window
        sort(begin(A), end(A));
        long i =0, j = 0,sum=0,ans = 1,N=A.size();
        for(;j<N;++j){
            sum+=A[j];
            
            if((j-i+1)*A[j] - sum > k ) sum-=A[i++];
            
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};

   /*  // Non Shrinkable Window Template
        sort(A.begin(),A.end());
        long i = 0,j=0,sum=0, N = A.size();
        for(; j < N ; ++j){
             sum += A[j];
            // We know that if we increase the value of the numbers they will become the same number after sorting and hence we do j-i+1 * A[j] , difference of this and the sum (of the numbers we found which are in our sliding window)
            // if difference of these two is <=  k => we can consider them in our max freq range => dont increase i(size of window) &expand window size by increasing j
            // if the difference is greater than k=> we need to delete the first elements of the window and hence we will be abel to get a window where the diff<=k 
            if((j-i+1)*A[j] - sum > k) sum-=A[i++];
        }
        // we are going to return the size of the window as it is the number of elements which can be taken
        // we did j-i & not j-i+1 as j is already>n
        return j-i;*/