// There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] 
// represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
// Return the city with the smallest number of cities that are reachable through some path and whose distance 
// is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
// Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

// Example 1:
// Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
// Output: 3
// Explanation: The figure above describes the graph. 
// The neighboring cities at a distanceThreshold = 4 for each city are:
// City 0 -> [City 1, City 2] 
// City 1 -> [City 0, City 2, City 3] 
// City 2 -> [City 0, City 1, City 3] 
// City 3 -> [City 1, City 2] 
// Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
// x---------------------------------------------------------------x-----------------------------------x-------------------------------------------x

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> distance(n, vector<int>(n, 1000000000)); // Initialize distance matrix with infinity

        for (int i = 0; i < n; ++i) {
            distance[i][i] = 0; // Distance to itself is 0
        }

        for (auto& edge : edges) {
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }

        // Floyd-Warshall algorithm to find all-pairs shortest path
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
        int ans = -1;
        int mini = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && distance[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            if (count <= mini) {
                mini = count;
                ans = i;
            }
        }
        return ans;
    }
};
