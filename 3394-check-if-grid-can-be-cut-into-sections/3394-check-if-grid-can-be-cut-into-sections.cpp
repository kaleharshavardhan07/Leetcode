class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    

    bool s1(vector<vector<int>>& x) {
        int s = x[0][0];
        int e = x[0][1];
        int count = 0;
        for (int i = 1; i < x.size(); i++) {

            
            if( e<=x[i][1] && e>x[i][0]){
                e=x[i][1];
            }
            else if( e==x[i][0]){
                count++;
                e=x[i][1];
            }    
        }
        return count>=2;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x;
        vector<vector<int>> y;
        for (auto it : rectangles) {
            x.push_back({it[0], it[2]});
            y.push_back({it[1], it[3]});
        }
        sort(x.begin(), x.end(), cmp);
        sort(y.begin(), y.end(), cmp);

        return s1(x) || s1(y);
    }
};

