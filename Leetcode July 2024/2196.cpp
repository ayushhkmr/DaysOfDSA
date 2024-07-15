// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] 
// indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.
// The test cases will be generated such that the binary tree is valid.

// Example 1:
// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.

x-------------------------------------------------------x------------------------------------x---------------------------------------x

class Solution {
public:
    static TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        const int N = 100001;
        bitset<N> seen = 0;
        int root = -1;
        int parent[N] = {0};//parent val
        TreeNode* node[N] = {NULL};// array for TreeNode*

        for (auto& d : descriptions) {
            int x = d[0], y = d[1], l = d[2];
            if (!seen[x]) {
                node[x] = new TreeNode(x);
                seen[x] = 1;
                if (parent[x] == 0)
                    root = x;
            }
            if (!seen[y]) {
                node[y] = new TreeNode(y);
                seen[y] = 1;
            }
            parent[y] = x;
            if (l)
                node[x]->left = node[y];
            else
                node[x]->right = node[y];
        }
        while (parent[root] != 0)// find real root
            root = parent[root];
        return node[root];
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
