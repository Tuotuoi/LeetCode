/*************************************************************************
	> File Name: leetcode-104.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时16分59秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int maxDepth(struct TreeNode* root){
    if(!root){
        return 0;
    }
    
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + MAX(left, right);
}
