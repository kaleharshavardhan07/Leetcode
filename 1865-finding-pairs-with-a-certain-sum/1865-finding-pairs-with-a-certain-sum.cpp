class FindSumPairs {
public:
    vector<int> n1;
    vector<int> n2;
    map<int,int>mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {

        n1 = nums1;

        n2 = nums2;
        for (int n : n2) {
            mp[n]++;
        }
    }

    void add(int index, int val) {
        if (n2.size() < index)
            return;

    mp[n2[index]]--;
        n2[index] += val;
        mp[n2[index]]++;
    }

    int count(int tot) {
        int c = 0;
        for (int n : n1) {
            int temp = tot - n;

            if (mp.find(temp) != mp.end()) {
                c = c + mp[temp];
            }
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */