class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int flag = 0;
        int k = strs.size();

        for (int i = 0; i < strs[0].size(); i++) {
            flag = 0;
            for (int j = 0; j < k - 1; j++) {

                if (strs[j][i] > strs[j + 1][i]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                count++;
                
            }
        }

        return count;
    }
};