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
    int getDepth(TreeNode* curr){
        if(curr == NULL) return 0;
        int leftDepth;
        int rightDepth;
        
        leftDepth = getDepth(curr->left);
        if(leftDepth == -1)return -1;

        rightDepth = getDepth(curr->right);
        if(rightDepth == -1)return -1;

        int result;
        if(abs(leftDepth - rightDepth) > 1) result = -1;
        else{
            result = 1 + max(leftDepth, rightDepth);
            
        }
        return result;
    }
    bool isBalanced(TreeNode* root) {
        return (getDepth(root)) == -1 ? false:true;
    }
};