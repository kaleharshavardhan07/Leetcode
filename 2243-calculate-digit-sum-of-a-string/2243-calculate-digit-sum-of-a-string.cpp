class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string new_s = ""; 
            int i = 0;
            while (i < s.length()) {
                int temp = 0;
                for (int j = i; j < i + k && j < s.length(); j++) {
                    temp += s[j] - '0'; 
                }
                new_s += to_string(temp);
                i += k; 
            }
            s = new_s; 
        }
        return s;
    }
};
