class Solution {
public:
// Binary Search Soln
// Time O(N.logN)
// Space O(1)
    bool binarySearch(vector<int>&a,int l,int r,int target){
       
        while( l<=r ){
            int m = l + (r-l)/2;
            if( a[m] == target ) return true;
            else if( a[m] > target) r = m - 1;
            else l = m + 1;
        }
        return false;
    }
    bool checkIfExist(vector<int>& a) {
        // we will be running a loop and finding if we have 2*a[i] element in the array if we do then return true
        sort(a.begin(),a.end());
        for( int i = 0; i < a.size()  ; i++ ){
            // Element divisible by 2
            if( (a[i]%2==0) && a[i]<0 )
            {
                // As greater negative elements will be towards left after sorting hence , search for a[i]/2
                if (binarySearch(a, i + 1, a.size() - 1, a[i] / 2)) return true;
            }
            else{
                // Element not divisible by 2, see if we can find a multiple, as low elements are towards left after sorting hence we are starting from left to find an element on the right
                 if (binarySearch(a, i + 1, a.size() - 1, 2 * a[i])) return true;
            }
        }
        return false;
    }
};