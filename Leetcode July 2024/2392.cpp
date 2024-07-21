// You are given a positive integer k. You are also given:

// a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
// a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
// The two arrays contain integers from 1 to k.

// You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

// The matrix should also satisfy the following conditions:

// The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
// The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
// Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.
// Example 1:
// Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
// Output: [[3,0,0],[0,0,1],[0,2,0]]
// Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
// The row conditions are the following:
// - Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
// - Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
// The column conditions are the following:
// - Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
// - Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
// Note that there may be multiple correct answers.

x---------------------------------------------------------------x-----------------------x-----------------------------------------------------x

class Solution {
public:
//topological sort, how?

    //use BFS Kahn's algorithm
    vector<int> topoSort(int k, vector<vector<int>> edges){
        vector<vector<int>> graph(k+1);
        vector<int> indegree(k+1,0);
        vector<int> res;


        //build graph & calculate indegrees
        for(vector<int>& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        //push nodes with no dependency
        for(int i=1; i<=k; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        //BFS
        while(!q.empty()){
            int cur = q.front(); q.pop();
            res.push_back(cur);

            for(int neigh: graph[cur]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        //check for cyle
        for(int i=1; i<=k; i++){
            if(indegree[i]!=0){
                return {};
            }
        }
        return res;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {

        vector<int> rowOrder = topoSort(k, rowConditions);
        vector<int> colOrder = topoSort(k, colConditions);

        //if we encountered a cycle in any condition, return empty array
        if(rowOrder.empty() || colOrder.empty()){
            return {};
        }

        vector<vector<int>> res(k, vector<int>(k,0));

        //build the result matrix
        for(int i=0; i<k; i++){
            int ele = rowOrder[i];
            for(int j=0; j<k; j++){
                if(colOrder[j]==ele){
                    res[i][j] = ele;
                }
            }
        }
        return res;
    }
};
