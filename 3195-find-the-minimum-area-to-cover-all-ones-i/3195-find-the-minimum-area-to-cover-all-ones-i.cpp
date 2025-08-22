class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
     int t=n;int b=0;
     int l=m;
     int r=0;


      for( int i=0;i<n;i++){
        for( int j=0;j<m;j++){

            if( grid[i][j]==1){
                t=min(t,i);
                b=max(b,i);
                l=min(l,j);
                r=max(r,j);

            }

        }
      }

      return (r-l+1)*(b-t+1);


    }
};