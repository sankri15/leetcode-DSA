class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* node, int num) {
        if (!node) return 0;
        if (!node->left && !node->right) {
            return num * 10 + node->val;
        }
        return dfs(node->left, num * 10 + node->val) + dfs(node->right, num * 10 + node->val);
    }
};