class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int carry = 0;
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int i = 0;
        while (i < num1.size() || i < num2.size() || carry) {
            int sum = carry;
            if (i < num1.size()) sum += num1[i] - '0';
            if (i < num2.size()) sum += num2[i] - '0';
            
            carry = sum / 10; 
            ans += to_string(sum % 10);
            
            i++;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
