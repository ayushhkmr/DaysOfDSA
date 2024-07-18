// You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes
// of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.
// Return the number of good leaf node pairs in the tree.
// Example 1:
// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
// Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.

x----------------------------------------------------x-----------------------x---------------------------------------------------------------x

class Solution {
public:
    void getPath(TreeNode* root, vector<string>& path, string& st){
        if(!root) return;
        if(!root->left && !root->right) path.push_back(st);
        if(root->left){
            st += 'l';
            getPath(root->left,path,st);
            st.pop_back();
        }
        if(root->right){
            st += 'r';
            getPath(root->right,path,st);
            st.pop_back();
        }
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        vector<string>path;
        string st = "";
        getPath(root, path, st);
        for(int i = 0; i < path.size(); i++){
            for(int j = i + 1; j < path.size(); j++){
                int k = 0;
                int tmp = 0;
                while(k < path[i].size() && k < path[j].size()){
                    if(path[i][k] != path[j][k]) break;
                    k++;
                }
                tmp += path[i].size() - k + path[j].size() - k;
                if(tmp <= distance) ans++;
            }
        }
        return ans;
    }  
};
