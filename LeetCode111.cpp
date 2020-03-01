/*************************************************************************
	> File Name: leetcode-111.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时19分14秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root){
    if(!root) return 0;
    if (root->left == NULL && root->right != NULL) {
        return 1 + minDepth(root->right);
    }
    if (root->left != NULL && root->right == NULL) {
        return 1 + minDepth(root->left);
    }
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    return 1 + (left > right ? right : left);
}
