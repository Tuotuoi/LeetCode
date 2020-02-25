/*************************************************************************
	> File Name: leetcode-160.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 21时12分00秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *pA = NULL,*pB = NULL;
    if(headA == NULL || headB == NULL)
    {
        return NULL;
    }
    pA = headA;
    pB = headB;
    while(pA != NULL)
    {
        while(pB != NULL)
        {
            if(pA == pB)
            {
                return pA;
            }
            pB = pB->next;
        }
        pB = headB;
        pA = pA->next;
    }
    return NULL;
}
