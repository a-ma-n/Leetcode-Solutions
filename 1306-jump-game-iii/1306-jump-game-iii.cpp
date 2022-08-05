class Solution {
public:
    // check if you can reach to any index with value 0.
    // https://leetcode.com/problems/jump-game-iii/discuss/1619031/C%2B%2BPython-Simple-Solution-w-Explanation-or-DFS-and-BFS-Traversals
    bool canReach(vector<int>& arr, int cur) {
        if(cur<0 || cur>size(arr) || arr[cur]<0) return false;
        arr[cur]*=-1;
        // returns true if arr[cur]==0
        return !arr[cur] || canReach(arr,cur+arr[cur]) || canReach(arr,cur-arr[cur]);
    }
};