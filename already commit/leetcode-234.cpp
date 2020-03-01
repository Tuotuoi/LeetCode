/*************************************************************************
	> File Name: leetcode-234.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 20时45分35秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int get_length(struct ListNode *head) {
    int n = 0;
    while(head) n += 1, head = head->next;
    return n;
}

struct ListNode *reverse(struct ListNode *head, int len) {
    struct ListNode ret, *p = head, *q;
    while (len--) {
        p = p->next;
    }
    ret.next = NULL;
    while(p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

bool isPalindrome(struct ListNode* head){
    if(!head) return true;
    int len = get_length(head);
    struct ListNode *p = head, *q = reverse(head, (len) / 2);
    while(q != NULL) {
        if(p->val != q->val) return false;
        p = p->next;
        q = q->next;
    }
    return true;



}
