/*************************************************************************
	> File Name: leetcode-142.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 15时49分37秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL) return NULL;
    int cnt = 0;
    struct ListNode *f_node, *s_node;
    struct ListNode *H = (struct ListNode *)malloc(sizeof(struct ListNode));
    H->next = head;
    f_node = s_node = H->next;
    if(s_node->next == NULL) return NULL;
    do {
        if(s_node->next != NULL)
        s_node = s_node->next;
        if(f_node->next != NULL)
        f_node = f_node->next;
        if(f_node != NULL && f_node->next == NULL) {
            return NULL;
        }
        if(f_node != NULL)
        f_node = f_node->next;
    } while(f_node != s_node);
    //if(f_node->next == NULL && s_node == NULL && f_node == NULL) return NULL;
    f_node = H->next;
    while (f_node != s_node && s_node->next != NULL && f_node->next != NULL) {
        f_node = f_node->next;
        s_node = s_node->next;
    }
    return s_node;
}
