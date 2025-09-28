/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getPath(TreeNode* curr, vector<int>path, vector<vector<int>>&paths){
        path.push_back(curr->val);
        if(!curr->left && !curr->right){
            paths.push_back(path);
            for(int i = 0; i< path.size(); i++){//clear path for next recursive
                path.pop_back();
            }
            return;
        }
        
        if(curr->left) getPath(curr->left, path, paths);
        if(curr->right) getPath(curr->right, path, paths);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>path;
        vector<string>ans;
        vector<vector<int>>paths;
        getPath(root, path, paths);
        for(vector<int> path:paths){
            string str = "";
            for(int i = 0;i<path.size();i++){
                str+=path[i];
                if(i!=path.size()-1)str+="->";
                cout<<path[i];
            }cout<<endl;
            ans.push_back(str);
        }
        return ans;
    }
};