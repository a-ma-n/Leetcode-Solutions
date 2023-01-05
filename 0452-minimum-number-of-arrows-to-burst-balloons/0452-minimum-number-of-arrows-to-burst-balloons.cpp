class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(), [](const vector<int> &o1, const vector<int> &o2) {
            return (o1[1] < o2[1]);
        });
        int arrows=1,xStart,xEnd,firstEnd=points[0][1];
        for(auto point:points){
            xStart=point[0];
            xEnd=point[1];
            if (firstEnd<xStart){
                arrows++;
                firstEnd=xEnd;
            }
        }
        return arrows;
    }
};