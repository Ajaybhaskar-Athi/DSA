#include<bits/stdc++.h>
using namespace std;
//Geek for Geeks
/*Problem Statement
In Geek Colony, there are n houses and p water pipes. Each house can have at most one pipe going into it and at most one pipe going out of it. You need to install pairs of tanks and taps in the colony based on the following rules:

Every house with one outgoing pipe but no incoming pipe receives a tank on its roof.
Every house with one incoming pipe and no outgoing pipe receives a tap.
The connections between houses are represented by three arrays:

a[]: Source houses (where pipes are coming from)
b[]: Destination houses (where pipes are going to)
d[]: Diameters of the pipes
Your task is to find the minimum diameter of the pipes connecting each tank to its corresponding tap.


*/

class Solution
{
public:
    void dfs(int house, vector<vector<pair<int, int>>>& g, vector<int>& in_deg, vector<int>& out_deg, vector<vector<int>>& ans, int& min_dia, int& tap) {
        for (const auto& pipe : g[house]) {
            int next_house = pipe.first;
            int diameter = pipe.second;
              min_dia = min(min_dia,diameter);

            if (in_deg[next_house] == 1 && out_deg[next_house] == 0) {
                    tap = next_house;
            }
            dfs(next_house, g, in_deg, out_deg, ans, min_dia, tap);
        }
    }

    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        vector<vector<pair<int, int>>> g(n + 1);
        vector<int> in_deg(n + 1, 0), out_deg(n + 1, 0);

        for (int i = 0; i < p; i++) {
            g[a[i]].push_back({b[i], d[i]});
            in_deg[b[i]]++;
            out_deg[a[i]]++;
        }

        vector<vector<int>> ans;

        for (int house = 1; house <= n; house++) {
            if (in_deg[house] == 0 && out_deg[house] == 1) {
                int min_dia = INT_MAX;
                int tap = -1;

                dfs(house, g, in_deg, out_deg, ans, min_dia, tap);

                if (tap != -1) {
                    ans.push_back({house, tap, min_dia});
                }
            }
        }

        return ans;
    }
};
