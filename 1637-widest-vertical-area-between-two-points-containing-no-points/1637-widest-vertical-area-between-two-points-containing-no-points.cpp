class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int>ret;
        for(int i=0;i<points.size();i++){
            ret.push_back(points[i][0]);
        }
        int max=INT_MIN;
        sort(ret.begin(),ret.end());
        for(int i=0;i<ret.size()-1;i++){
            if(max<abs(ret[i]-ret[i+1])){
                max=abs(ret[i]-ret[i+1]);
            }
        }
        return max;
    }
};