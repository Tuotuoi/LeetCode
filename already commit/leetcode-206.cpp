/*************************************************************************
	> File Name: leetcode-206.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时13分32秒
 ************************************************************************/
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *H = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p, *q;
    if(head == NULL) return NULL;
    H->next = head;
    p = H->next;
    H->next = NULL;
    while(p) {
        q = p->next;
        p->next = H->next;
        H->next = p;
        p = q;
    }
    return H->next;
}
