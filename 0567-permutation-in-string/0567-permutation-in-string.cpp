class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        
        if (n1 > n2) return false;  
        
        vector<int> s1_count(26, 0), window_count(26, 0);
        
        for (char c : s1) {
            s1_count[c - 'a']++;
        }
        
        for (int i = 0; i < n2; i++) {
            window_count[s2[i] - 'a']++;
            
            if (i >= n1) {
                window_count[s2[i - n1] - 'a']--;
            }
            
            if (s1_count == window_count) {
                return true; 
            }
        }
        
        return false;  
    }
};
