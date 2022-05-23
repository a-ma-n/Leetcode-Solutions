// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    vector<int> a;
    void ss( vector<int> set,int l,int r,int sum=0){
        if(l>r){
            a.push_back(sum);
            //cout<<sum<<" ";
            return;
        }
        //including that element
        ss(set,l+1,r,sum+set[l]);
        //excluding that element
        ss(set,l+1,r,sum);
    }
    
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
       ss(arr,0,N-1,0);
       return a;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends