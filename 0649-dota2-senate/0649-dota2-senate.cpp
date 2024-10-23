class Solution {
public:
    string predictPartyVictory(string senate) {
          queue<int> radiant, dire;
    int n = senate.size();

    // Fill the queues with their respective indices
    for (int i = 0; i < n; ++i) {
        if (senate[i] == 'R') {
            radiant.push(i);
        } else {
            dire.push(i);
        }
    }

    // Process banning each other
    while (!radiant.empty() && !dire.empty()) {
        int r = radiant.front();
        int d = dire.front();
        radiant.pop();
        dire.pop();

        // The senator with the smaller index bans the other
        if (r < d) {
            radiant.push(r + n); // The Radiant senator comes back for the next round
        } else {
            dire.push(d + n); // The Dire senator comes back for the next round
        }
    }

    // If the Radiant queue is non-empty, Radiant wins, otherwise Dire wins
    return radiant.empty() ? "Dire" : "Radiant";
    }
};