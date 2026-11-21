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
    int maxdepth(TreeNode* p){
        if(p == nullptr){
            return 0;
        }

        return 1+max(maxdepth(p->left), maxdepth(p->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int left = maxdepth(root->left);
        int right = maxdepth(root->right);

        if(abs(left - right) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
