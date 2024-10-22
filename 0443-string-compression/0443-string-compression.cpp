class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1; // Initialized to 1
        int sum = 0;
        int n = chars.size();
        vector<char> ret;

        for (int i = 0; i < n; i++) { // changed condition to n, as we need to process the last character too
            if (i < n - 1 && chars[i] == chars[i + 1]) { // i < n - 1 added to avoid out of bound access
                count++;
            } else {
                ret.push_back(chars[i]);
                sum++;

                if (count > 1) {
                    string count_str = to_string(count); // Convert count to string to extract digits
                    for (char c : count_str) {
                        ret.push_back(c);
                        sum++;
                    }
                }

                count = 1; // Reset count to 1
            }
        }
        
        chars.clear();
        for (char c : ret) {
            chars.push_back(c);
        }
        return sum;
    }
};
