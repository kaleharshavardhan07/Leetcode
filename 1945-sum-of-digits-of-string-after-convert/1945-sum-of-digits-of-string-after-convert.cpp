class Solution {
public:
    int getLucky(string s, int k) {
      
        string num;
        for (char c : s) {
            int digitValue = (c - 'a') + 1; 
            num += to_string(digitValue); 
        }

      
        for (int i = 0; i < k; i++) {
            int sum = 0;
            for (char digit : num) {
                sum += (digit - '0');
            }
            num = to_string(sum);
        }

        return stoi(num);
    }
};
