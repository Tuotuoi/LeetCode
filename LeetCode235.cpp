/*************************************************************************
	> File Name: LeetCode235.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月01日 星期日 22时03分56秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(p->val > q->val) {
        struct TreeNode *temp = p;
        p = q;
        q = temp;
    }
    while(root->val < p->val || root->val > q->val ) {
        if(root->val < p->val) root = root->right;
        else if(root->val > q->val) root = root->left;
    }
    return root;
}
