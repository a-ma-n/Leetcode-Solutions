class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        while(stones.size() > 1){
            int a = stones[stones.size()-1];
            int b = stones[stones.size()-2];
            stones.pop_back();
            stones.pop_back();
            stones.push_back(a-b);
            sort(stones.begin(),stones.end());
        }
        return stones[0];
        // return 0;   
    }
};