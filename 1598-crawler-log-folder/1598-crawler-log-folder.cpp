class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count = 0;
        for (string c : logs) {
            if (c == "../") {
                if (count == 0) {
                    continue;
                } else {
                    count--;
                }
            } else if (c == "./") {
                continue;
            } else {
                count++;
            }
        }
        return count;
    }
};