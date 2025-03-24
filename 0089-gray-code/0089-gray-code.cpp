class Solution {
public:
      void solve(int n, string temp, vector<string>& ret, unordered_set<string>& visited) {
        if (ret.size() == (1 << n)) return;

        for (int i = n - 1; i >= 0; i--) {
            string temp1 = temp;
            temp1[i] = (temp1[i] == '0') ? '1' : '0';

            if (visited.find(temp1) == visited.end()) {
                visited.insert(temp1);
                ret.push_back(temp1);
                solve(n, temp1, ret, visited); 
                if (ret.size() == (1 << n)) return; 
            }
        }
    }

    vector<int> grayCode(int n) {
        vector<int> result;
        vector<string> binaryGray;
        unordered_set<string> visited;

        string temp(n, '0'); 
        visited.insert(temp);
        binaryGray.push_back(temp);

        solve(n, temp, binaryGray, visited);

        for (const auto& bin : binaryGray)
            result.push_back(stoi(bin, nullptr, 2));

        return result;
    }

};