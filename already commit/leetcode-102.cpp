/*************************************************************************
	> File Name: leetcode-102.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时16分30秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(root == NULL) {
        *returnSize = 0;
        return 0;
    }
    int **arr = (int **)malloc(sizeof(int *) * 2000);
    struct TreeNode *p = root;
    struct TreeNode *q[2000];
    int front = 0, rear = 0, i = 0;
    q[(rear++)] = p;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 2000);
    while(front != rear) {
        int size = rear - front;
        arr[i] = (int *)malloc(sizeof(int) * size);
        (*returnColumnSizes)[i] = size;
        for(int j = 0; j < size; j++) {
            p = q[front++];
            if(p != NULL && p->left != NULL) {
                q[rear++] = p->left;
            }
            if(p != NULL && p->right != NULL) {
                
                q[rear++] = p->right;
            }
            arr[i][j] = p->val;
        }
        i++;
    }
    *returnSize = i;
    return arr;
}
