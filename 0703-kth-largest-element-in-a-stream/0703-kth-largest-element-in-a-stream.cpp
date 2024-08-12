#include <vector>
#include <queue>
#include <algorithm>

class KthLargest {
private:
    int key;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int size;

public:
    KthLargest(int k, std::vector<int>& nums) : key(k), size(0) {
        // Initialize the min-heap with the first 'k' elements
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (size < key) {
            minHeap.push(val);
            size++;
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }

        return minHeap.top();
    }
};
