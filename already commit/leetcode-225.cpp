/*************************************************************************
	> File Name: leetcode-225.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 20时47分22秒
 ************************************************************************/
typedef struct MyQueue{
    int *data;
    int head, tail;
    int size, cnt;
} MyQueue;

MyQueue *MyQueueCreate(int size) {
    MyQueue *q = (MyQueue *)malloc(sizeof(MyQueue));
    q->data = (int *)malloc(sizeof(int) * size);
    q->head = q->tail = 0;
    q->cnt = 0;
    q->size = size;
    return q;
}

void MyQueue_push(MyQueue *obj, int x) {
    if(obj == NULL) return ;
    if(obj->cnt == obj->size) return ;
    obj->data[obj->tail ++] = x;
    if(obj->tail == obj->size) obj->tail -= obj->size;
    obj->cnt++;
    return ;
}

int MyQueue_pop(MyQueue *obj) {
    if(obj == NULL) return 0;
    if(obj->cnt == 0) return 0;
    obj->head += 1;
    if(obj->head == obj->size) obj->head -= obj->size;
    obj->cnt -= 1;
    return 1;
} 

int MyQueue_front(MyQueue *obj) {
    return obj->data[obj->head];
}

int MyQueue_empty(MyQueue *obj) {
    return obj->cnt == 0;
}

void MyQueue_free(MyQueue *obj) {
    if(obj == NULL) return;
    free(obj->data);
    free(obj);
    return ;
}


typedef struct {
    MyQueue *q1,*q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    int size = 1024;
    MyStack *s = (MyStack *)malloc(sizeof(MyStack));
    s->q1 = MyQueueCreate(size);
    s->q2 = MyQueueCreate(size);
    return s;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if(!MyQueue_empty(obj->q1)) {
        MyQueue_push(obj->q1,x);
    } else {
        MyQueue_push(obj->q2,x);
    }
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    MyQueue *p = MyQueue_empty(obj->q1) ? obj->q2 : obj->q1;
    MyQueue *q = MyQueue_empty(obj->q1) ? obj->q1 : obj->q2;
    int element = MyQueue_front(p);
    MyQueue_pop(p);
    while(!MyQueue_empty(p)) {
        MyQueue_push(q,element);
        element = MyQueue_front(p);
        MyQueue_pop(p);
    }
    return element;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
     MyQueue *p = MyQueue_empty(obj->q1) ? obj->q2 : obj->q1;
    MyQueue *q = MyQueue_empty(obj->q1) ? obj->q1 : obj->q2;
    int element;
    while(!MyQueue_empty(p)) {
        element = MyQueue_front(p);
        MyQueue_pop(p);
        MyQueue_push(q, element);
    }
    return element;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    return MyQueue_empty(obj->q1) && MyQueue_empty(obj->q2);
}

void myStackFree(MyStack* obj) {
    if(obj == NULL) return ;
    MyQueue_free(obj->q1);
    MyQueue_free(obj->q2);
    free(obj);
    return ;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
