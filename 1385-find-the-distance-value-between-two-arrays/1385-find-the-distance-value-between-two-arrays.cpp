// Binary Search Soln
// Time: O(N.logM)
// Space: O(1)

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int distanceValue = 0;
        sort(arr2.begin(),arr2.end());
        
        for(int p1 = 0; p1<arr1.size() ; p1++ ){
            int ai = arr1[p1];
            bool addNum = true;
            int l = 0 ; 
            int r = arr2.size()-1;
            int m = -1;
            
            while(l<=r){
                m = l + (r-l)/2;
                int aj = arr2[m];
                if(abs(aj-ai)<=d){
                    addNum=false;
                    break;
                }
                else if(aj>ai)
                    r = m - 1;
                else 
                    l = m + 1;
            }
            if(addNum) distanceValue++;
        }
        return distanceValue;
    }
};