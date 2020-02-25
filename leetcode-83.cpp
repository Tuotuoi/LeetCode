/*************************************************************************
	> File Name: leetcode-83.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 21时13分25秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *p = head;
    struct ListNode *temp = NULL;
    while (p->next != NULL) {
        if (p->next->val == p->val) {
            temp = p->next;
            p->next = p->next->next;
            free(temp);
        } else {
            p = p->next;
        }        
    }
    return head;
}

