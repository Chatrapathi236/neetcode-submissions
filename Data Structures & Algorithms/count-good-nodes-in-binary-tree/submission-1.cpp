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
    int dfs(TreeNode* root, int maxVal){
        int count = 0;
        if(root == nullptr){
            return 0;
        }
        if(root->val >= maxVal){
            count = 1;
            maxVal = root->val;
        }

        count += dfs(root->right, maxVal);
        count += dfs(root->left, maxVal);

        return count;
    }
    int goodNodes(TreeNode* root) {
        int maxVal = INT_MIN;
        return dfs(root, maxVal);
    }
};
