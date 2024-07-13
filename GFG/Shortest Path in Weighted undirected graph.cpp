// You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. 
// Find the shortest path between the vertex 1 and the vertex n,  if there exists a path, and return a list of 
// integers whose first element is the weight of the path, and the rest consist of the nodes on that path. 
// If no path exists, then return a list containing a single element -1.
// The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

// Note: The driver code here will first check if the weight of the path returned is equal to the sum 
// of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. 
// In case the list contains only a single element (-1) it will simply output -1. 

Examples :

Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
Output: 5
Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5.

x------------------------------------------------------------------x------------------------x---------------------------------------------------x

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i:edges){
            int weight = i[2];
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        vector<int> distance(n+1,INT_MAX);
        vector<int> parent(n+1,-1);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        
        distance[1] = 0;
        parent[1] = 0;
        q.push({0,1});
        
        
        while(!q.empty()){
            int cur = q.top().second;
            int d = q.top().first;
            q.pop();
            
            for(auto k: adj[cur]){
                int neighbour = k.first;
                int weight = k.second;
                
                if(d + weight < distance[neighbour]){
                    distance[neighbour] = d + weight;
                    parent[neighbour] = cur;
                    q.push({distance[neighbour],neighbour});
                }
            }
        }
        
        if(distance[n] == INT_MAX) return {-1};
        
        vector<int> ans;
        int temp = n;
        while(temp != 0){
            ans.push_back(temp);
            temp = parent[temp];
        }
        ans.push_back(distance[n]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
