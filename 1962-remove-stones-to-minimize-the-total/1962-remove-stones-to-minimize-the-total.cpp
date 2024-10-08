#include <queue>
#include <vector>

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap(piles.begin(), piles.end());
        
        for (int i = 0; i < k; ++i) {
            int largest = maxHeap.top(); 
            maxHeap.pop(); 
            largest = largest - largest / 2;
            maxHeap.push(largest);
        }
        
        int sum = 0;
        while (!maxHeap.empty()) {
            sum += maxHeap.top();
            maxHeap.pop();
        }
        
        return sum;
    }
};
