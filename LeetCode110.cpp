/*************************************************************************
	> File Name: leetcode-110.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时18分08秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int tree_high(struct TreeNode *node) {
    if(node == NULL) {
        return 0;
    }
    int left = tree_high(node->left);
    if(left == -1) return -1;
    int right = tree_high(node->right);
    if(right == -1) return -1;
    if(abs(left - right) > 1) return -1;
    return 1 + (left > right ? left : right); 

}
bool isBalanced(struct TreeNode* root){
    if(tree_high(root) == -1) return false;
    return true;
}
