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
    int minDepth(TreeNode* root) {
       queue<TreeNode*>q;
       if (!root) return 0;
       int depth = 0;
       q.push(root);
       while(!q.empty()){
        depth++;
        int size = q.size();
        for(int i = 0;i<size;i++){
            TreeNode* curr = q.front();q.pop();
            if(!curr->left && !curr->right) return depth;
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        
       }
       return depth;

    }
};