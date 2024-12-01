class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                int a = arr[i], b = arr[j];
                if ((b == 2 * a) || (a == 2 * b)) return true;
            }
        }
        return false;
    }
};