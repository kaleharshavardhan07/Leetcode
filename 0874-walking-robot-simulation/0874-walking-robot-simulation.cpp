class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions: north, east, south, west
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;  // Start facing north
        int x = 0, y = 0;
        int maxDist = 0;

        // Store obstacles in a set for quick lookup
        unordered_set<string> obstacleSet;
        for (auto& obs : obstacles) {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }

        for (int command : commands) {
            if (command == -1) {
                // Turn right
                dir = (dir + 1) % 4;
            } else if (command == -2) {
                // Turn left
                dir = (dir + 3) % 4;
            } else {
                for (int i = 0; i < command; ++i) {
                    int nextX = x + directions[dir].first;
                    int nextY = y + directions[dir].second;

                    if (obstacleSet.find(to_string(nextX) + "," + to_string(nextY)) != obstacleSet.end()) {
                        break; // Stop if there's an obstacle
                    }

                    x = nextX;
                    y = nextY;
                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;
    }
};
