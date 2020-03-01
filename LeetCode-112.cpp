/*************************************************************************
	> File Name: leetcode-112.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时18分47秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int sum){
    if(root == NULL) {
        return false;
    }
    sum -= root->val;
    if(sum == 0 && root->left == NULL && root->right == NULL) {
        return true;
    }
    if(hasPathSum(root->left,sum) ) return true;
    if(hasPathSum(root->right,sum)) return true;
    return false;
}
