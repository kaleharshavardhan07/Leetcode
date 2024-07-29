class Solution {
public:
    int numTeams(vector<int>& ratings) {
        int n = ratings.size();
        if (n < 3)
            return 0;

        int count = 0;

    
        for (int j = 0; j < n; ++j) {
            int left_less = 0, left_greater = 0;
            int right_less = 0, right_greater = 0;

            for (int i = 0; i < j; ++i) {
                if (ratings[i] < ratings[j])
                    ++left_less;
                if (ratings[i] > ratings[j])
                    ++left_greater;
            }

            for (int k = j + 1; k < n; ++k) {
                if (ratings[k] < ratings[j])
                    ++right_less;
                if (ratings[k] > ratings[j])
                    ++right_greater;
            }

           
            count += left_less * right_greater;
            count += left_greater * right_less;
        }

        return count;
    }
};