class Solution {
public:
         int maxEnvelopes(vector<vector<int>>& envelopes) {
        
  sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) 
             -> bool {return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];});
        vector<int> dp;
        for (auto& env : envelopes) {
            int height = env[1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
    }
};


// class Solution {
// public:
    
    
//     static bool compareEnv(vector<int> a,vector<int> b){
//         if(a[0]!=b[0]){
//             return a[0]<b[0];
//         }
//         else{
//             return a[1]<b[1];
//         }
//     }
    
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         sort(envelopes.begin(),envelopes.end(),compareEnv);
        
//         for(int i=0;i<envelopes.size();i++){
//             cout<<"index :"<<i<<" ; "<<envelopes[i][0]<<","<<envelopes[i][1]<<endl;
//         }
//      cout<<"---------------------------\n";
//         int count=0;
//         // for(int i=0;i<envelopes.size();i++){
//         int i=0;
//             for(int j=i+1;j<envelopes.size();j++){
                
//                 cout<<"i is: "<<i<<"; "<<envelopes[i][0]<<","<<envelopes[i][1]<<"-";
//          cout<<"j is: "<<j<<"; "<<envelopes[j][0]<<","<<envelopes[j][1]<<endl;
//                 if(envelopes[i][0]<envelopes[j][0] && envelopes[i][1]<envelopes[j][1]){
                    
//          cout<<"inc\n\n";
//                     count++;
//                     i=j;
//                 }
//             }

//         return count+1;
//     }
// };

/*

[[5,4],[6,4],[6,7],[2,3]]
[[1,1],[1,1],[1,1]]
[[1,3],[3,5],[6,7],[6,8],[8,4],[9,5]]

*/