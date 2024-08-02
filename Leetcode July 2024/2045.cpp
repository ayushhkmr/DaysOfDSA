// A city is represented as a bi-directional connected graph with n vertices where each vertex 
// is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, 
// where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. 
// Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. 
// The time taken to traverse any edge is time minutes.

// Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. 
// All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the
// signal is green. You cannot wait at a vertex if the signal is green.

// The second minimum value is defined as the smallest value strictly larger than the minimum value.

// For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
// Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.
// Notes:

// You can go through any vertex any number of times, including 1 and n.
// You can assume that when the journey starts, all signals have just turned green.

// Example 1:   
// Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
// Output: 13
// Explanation:
// The figure on the left shows the given graph.
// The blue path in the figure on the right is the minimum time path.
// The time taken is:
// - Start at 1, time elapsed=0
// - 1 -> 4: 3 minutes, time elapsed=3
// - 4 -> 5: 3 minutes, time elapsed=6
// Hence the minimum time needed is 6 minutes.

// The red path shows the path to get the second minimum time.
// - Start at 1, time elapsed=0
// - 1 -> 3: 3 minutes, time elapsed=3
// - 3 -> 4: 3 minutes, time elapsed=6
// - Wait at 4 for 4 minutes, time elapsed=10
// - 4 -> 5: 3 minutes, time elapsed=13
// Hence the second minimum time is 13 minutes.

// x------------------------------------------x-------------------------------x-------------------------------------------------x

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            adj[it[0] - 1].push_back(it[1] - 1);
            adj[it[1] - 1].push_back(it[0] - 1);
        }
        vector<priority_queue<int>> dist(n);
        for (int i = 0; i < n; i++) {
            dist[i].push(1e8);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        dist[0].pop();
        dist[0].push(0);
        while (!pq.empty()) {
            int dis = pq.top().first;
            int cur = pq.top().second;
            pq.pop();
            int k = dis / change;
            if ((k % 2) == 1) {
                dis += (change - (dis% change));
            }
            for (auto it : adj[cur]) {
                int distance = dis + time;
                if (dist[it].top() == 1e8) {
                    dist[it].pop();
                    dist[it].push(distance);
                    pq.push({distance, it});
                } else if (dist[it].size() < 2 && dist[it].top() != distance) {
                    dist[it].push(distance);
                    pq.push({distance, it});
                } else {
                    if (dist[it].top() > distance) {
                        dist[it].pop();
                        dist[it].push(distance);
                        pq.push({distance, it});
                    }
                }
            }
        }
        return dist[n-1].top();
    }
};