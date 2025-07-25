class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {

        int st = 0;
        int curr = 0;
        int last = 0;
        map<int, int> mp;
        int flag = 0;
        int n = students.size();
        while (curr < sandwiches.size()) {
            if (last == st && flag != 0)
                break;
            if (mp.find(st) == mp.end()) {

                if (students[st] == sandwiches[curr]) {

                    curr++;
                    mp[st]++;
                    last = st;
                    st++;

                } else {
                    st++;
                }
            } else {

                st++;
            }
            st = st % n;
            flag = 1;
        }

        return students.size() - mp.size();
    }
};