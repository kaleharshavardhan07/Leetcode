class Solution {
public:
   
bool isPalindrome(const std::string& s) {
    std::string filtered;
    
    // Filter and normalize the string
    for (char c : s) {
        if (std::isalnum(c)) {
            filtered += std::tolower(c);
        }
    }
    
    // Check if the filtered string is a palindrome
    int left = 0;
    int right = filtered.size() - 1;
    
    while (left < right) {
        if (filtered[left] != filtered[right]) {
            return false;
        }
        ++left;
        --right;
    }
    
    return true;
}
};