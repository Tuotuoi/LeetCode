/*************************************************************************
	> File Name: leetcode-141.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 21时11分01秒
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

bool hasCycle(struct ListNode *head) {
    if(head == NULL){
        return 0;
    }
    struct ListNode *f_node,*s_node;
	f_node = head;
    s_node = head;
	while(f_node->next != NULL && s_node->next != NULL){
		if(f_node->next==s_node->next->next){
			return 1;
		}
		f_node = f_node->next;
        s_node = s_node->next->next;
        if(f_node == NULL||s_node == NULL){
            return 0;
        }
	}
	return 0;
}
