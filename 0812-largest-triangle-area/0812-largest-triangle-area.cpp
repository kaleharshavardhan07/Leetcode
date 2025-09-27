class Solution {
public:
    double dis( vector<int>a,vector<int>b){
      double d=(a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
      d=sqrt(d);
      return d;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int k=points.size();
        double maxi=0;
        for( int i=0;i<k;i++){
            for( int j=i+1;j<k;j++){
                for( int l=j+1;l<k;l++){
                    double a= dis(points[i],points[j]);
                    double b= dis(points[i],points[l]);
                    double c= dis(points[l],points[j]);
                     double s = (a + b + c) / 2.0; 
                    double area = sqrt(s * (s - a) * (s - b) * (s - c));
                    maxi=max(maxi,area);
                }
            }
        }
        return maxi;
    }
};