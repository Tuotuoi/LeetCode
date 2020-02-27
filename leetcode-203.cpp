/*************************************************************************
	> File Name: leetcode-203.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 20时44分41秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head == NULL) return NULL;
    struct ListNode *H = (struct ListNode *)malloc(sizeof(struct ListNode));
    H->next = head;
    struct ListNode *p = H, *q;
    while(p != NULL && p->next != NULL) {
        if(p->next->val == val) {
            q = p->next;
            p->next = q->next;
            free(q);
        }
        else
        p = p->next;
    }
    return H->next;

}
