class Solution {
public:
    int minPartitions(string n) {
        return (int)*max_element(n.begin(), n.end())-48;
    }
};