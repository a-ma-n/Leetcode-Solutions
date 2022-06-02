class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> m;
    for (auto n : nums) {
        m[n]++;
    }
    priority_queue<pair<int,int>>pq;        
    for(auto it:m){
        pq.push(make_pair(it.second,it.first)); 
    }
    vector<int> ans;
    while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
  }
};