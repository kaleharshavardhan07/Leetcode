class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // vector<int>points;
        int max=INT_MIN;
        sort(points.begin(),points.end());
        for(int i=0;i<points.size()-1;i++){
            // points.push_back(points[i][0]);
             if(max<abs(points[i][0]-points[i+1][0])){
                max=abs(points[i][0]-points[i+1][0]);
            }
        }
        
        // for(int i=0;i<points.size()-1;i++){
        //     if(max<abs(points[i]-points[i+1])){
        //         max=abs(points[i]-points[i+1]);
        //     }
        // }
        // pointsurn max;
        return max;
    }
};