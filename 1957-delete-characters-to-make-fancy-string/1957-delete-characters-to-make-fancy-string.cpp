class Solution {
public:
    string makeFancyString(string s) {
        string k = "";
        for (char c : s) {
            int n = k.size();
            if (n < 2 || !(k[n - 1] == c && k[n - 2] == c)) {
                k += c;
            }
        }
        return k;
    }
};
