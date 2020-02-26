/*************************************************************************
	> File Name: leetcode-101.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时15分49秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSymmetric(struct TreeNode* root){
if(!root)
        return 1;
    if(!root->left && !root->right)
        return 1;
    if(!root->left || !root->right)
        return 0;

    /*init queue*/
    struct TreeNode* q1[1000];
    struct TreeNode* q2[1000];
    int front1, rear1, front2, rear2;
    front1 = rear1 = front2 = rear2 = -1;
    q1[++rear1] = root->left;
    q2[++rear2] = root->right;
    struct TreeNode *a, *b;
    while(front1 < rear1){
        a = q1[++front1];
        b = q2[++front2];
        if(!a && !b)
            continue;
        if(!a || !b)
            return 0;
        if(a->val != b->val)
            return 0;
        q1[++rear1] = a->left;
        q2[++rear2] = b->right;
        q1[++rear1] = a->right;
        q2[++rear2] = b->left;
    }
    return 1;

}
