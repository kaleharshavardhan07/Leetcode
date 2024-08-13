class Solution {
public:
    vector<string> solve(string digit, string s, vector<string>& memo,
                         vector<string>& ret) {

        if (digit.empty()) {
            ret.push_back(s);

        } else {
            int k = digit[0]-'0';
            for (char c : memo[k]) {
                solve(digit.substr(1), s + c, memo, ret);
            }
        }
        return ret;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string s;
        if(digits.empty())return ret;
        vector<string> memo = {{},      {},      {"abc"},  {"def"}, {"ghi"},
                               {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}};
       return solve(digits, s, memo, ret);

    }
};