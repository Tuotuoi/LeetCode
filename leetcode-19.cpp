/*************************************************************************
	> File Name: leetcode-19.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 21时07分23秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *H = (struct ListNode *)malloc(sizeof(struct ListNode));
    H->next = head;
    struct ListNode *p = H->next;
    struct ListNode *q = H;
    int len = 0,i = 0;
    while(p) {
        len++;
        p = p->next;
    }
    p = H->next;
    while(i < len - n) {
        q = p;
        p = p->next;
        i++;
    }
    q->next = p->next;
    free(p);
    return H->next;
}
