class Solution {
public:
    int minPartitions(string n) {
        int m=n.size();
        sort(n.begin(),n.end());
        m=n[m-1];
        return (m-48);
    }
};