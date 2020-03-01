/*************************************************************************
	> File Name: leetcode-100.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时15分25秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(p == NULL && q == NULL) return true;
    else if(p != NULL && q == NULL) return false;
    else if(p == NULL && q != NULL) return false;
    else if(p != NULL && q != NULL)
    {
        if(p->val != q->val) return false;
        else return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
    else
    return true;
}
