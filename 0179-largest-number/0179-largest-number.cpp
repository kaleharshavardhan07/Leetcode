class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> adj[10];

        auto cmp=[](const string & a, const string& b) { return a + b < b + a; };
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            string s = to_string(a);
            int k = s[0] - '0';
            adj[k].push_back(s);
        }
        for (int i = 0; i < 10; i++) {
            sort(adj[i].begin(), adj[i].end(), cmp);
            // reverse(adj[i].begin(),adj[i].end());
        }
        string s;
        for (int i = 9; i >= 0; i--) {
            for (int j = adj[i].size() - 1; j >= 0; j--) {
                s += adj[i][j];
            }
        }
        size_t firstNonZero = s.find_first_not_of('0');
    
  
    if (firstNonZero == std::string::npos) {
        return "0";
    }

    s.erase(0, firstNonZero);
    
      
        return s;
    }
};