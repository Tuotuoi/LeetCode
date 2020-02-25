/*************************************************************************
	> File Name: leetcode-24.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 21时10分10秒
 ************************************************************************/
struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *H = (struct ListNode *)malloc(sizeof(struct ListNode));
    H->next = head;
    struct ListNode *head_node,*mid_node,*tail_node,*T;
    head_node = H;
    tail_node = H;
    int cnt = 0;
    while(tail_node) {
        if(cnt < 2) {
            cnt++;
            tail_node = tail_node->next;
            continue;
        }
        cnt = 0;
        mid_node = head_node->next;
        T = tail_node->next;
        head_node->next = tail_node;
        tail_node->next = mid_node;
        mid_node->next = T;
        head_node = mid_node;
        tail_node = mid_node;
    }
    return H->next;
}
