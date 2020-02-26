/*************************************************************************
	> File Name: leetcode-107.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时17分25秒
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
#define MAXSIZE 1000
#define SWAP(a, b) {\
    __typeof(a) __temp;\
    __temp = b;\
    b = a;\
    a = __temp;\
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int i, j, front = 0, rear = 0;
    int **re = (int**)calloc(MAXSIZE, sizeof(int*));
    struct TreeNode *p, *queue[MAXSIZE];
    *returnColumnSizes = (int*)calloc(MAXSIZE, sizeof(int));
    *returnSize = 0;
    if(root) {
        queue[rear++%MAXSIZE] = root;
        while(front != rear){
            (*returnColumnSizes)[*returnSize] = rear - front;
            re[*returnSize] = (int*)calloc(rear - front, sizeof(int));
            for(i = 0;i < (*returnColumnSizes)[*returnSize];++i) {
                p = queue[front++%MAXSIZE];
                re[*returnSize][i] = p->val;
                if(p->left) queue[(rear++) % MAXSIZE] = p->left;
                if(p->right) queue[(rear++) % MAXSIZE] = p->right;
            }
            (*returnSize)++;
        }
        for(i = 0, j = *returnSize - 1;i < j;++i, --j){
            SWAP(re[i], re[j]);
            SWAP((*returnColumnSizes)[i], (*returnColumnSizes)[j]);
        }
    }
    return re;
}
