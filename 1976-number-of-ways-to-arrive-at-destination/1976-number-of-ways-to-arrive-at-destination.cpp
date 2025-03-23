#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
   void solve(vector<int>& vis, map<int,int>& times, map<int, vector<pair<int, int>>>& mp, int currTime, int target, int curr) {
        if (curr == target) {
            times[currTime]++;
            return;
        }

        for (const auto& p : mp[curr]) {
            if (!vis[p.first]) { 
                vis[p.first] = 1;
                solve(vis, times, mp, currTime + p.second, target, p.first);
                vis[p.first] = 0; 
            }
        }
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int> vis(n, 0);
        map<int,int> times;  
        map<int, vector<pair<int, int>>> mp; 

   
        for (int i = 0; i < roads.size(); i++) {
            int a = roads[i][0];
            int b = roads[i][1];
            int c = roads[i][2];

            mp[a].push_back({b, c});
            mp[b].push_back({a, c});
        }
int mini=INT_MAX;
        solve(vis, times, mp, 0, n-1, 0);
        for( auto it : times){
            mini=min(mini,it.first);
        }

        return times[mini];
       
    }
};
