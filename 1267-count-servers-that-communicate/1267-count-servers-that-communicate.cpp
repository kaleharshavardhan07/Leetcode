class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int x= grid.size();
        int y= grid[0].size();
        map<int,int>row;
        map<int,int>col;

        for( int i=0;i< x;i++){
            for( int j=0;j<y;j++){
                if( grid[i][j]==1){
                    row[i]++;
                    col[j]++;
                }

            }
        }
        int sum=0;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                    sum++;
                }
            }
        }

        return sum;
    }
};