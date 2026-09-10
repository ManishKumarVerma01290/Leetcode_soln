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
    void solve(TreeNode* node, int& ans, int& sum, int& count) {
        if(node == nullptr) {
            return;
        }

        int leftSum = 0, rightSum = 0;
        int leftCount = 0, rightCount = 0;

        solve(node->left, ans, leftSum, leftCount);
        solve(node->right, ans, rightSum, rightCount);

        sum = node->val + leftSum + rightSum;
        count = 1 + leftCount + rightCount;

        if(sum / count == node->val) {
            ans++;
        }
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        int sum = 0;
        int count = 0;
        solve(root, ans, sum, count);
        return ans;
    }
};