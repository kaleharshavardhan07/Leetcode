#include <set>

class MyHashSet {
private:
    std::set<int> nums;

public:
    MyHashSet() {}

    void add(int key) {
        nums.insert(key);
    }

    void remove(int key) {
        nums.erase(key); 
    }

    bool contains(int key) {
        return nums.find(key) != nums.end(); 
    }
};
