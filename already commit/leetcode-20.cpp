/*************************************************************************
	> File Name: leetcode-20.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月27日 星期四 20时48分02秒
 ************************************************************************/
bool isValid(char * s){
    int len = strlen(s);
    char *stack = (char *)malloc(sizeof(char) * len);
    if(len == 0) return true;
    if(len == 1) return false;
    int top = -1;
    for(int i = 0; i < len; i++) {

        if(*(s + i) == ')') {
            if(top != -1 && *(stack + top) == '(') {
                top --;
            }
            else return false;
        }
        else if(*(s + i) == ']') {
            if(top != -1 && *(stack + top) == '[') {
                top --;
            }
            else return false;
        }
        else if(*(s + i) == '}') {
            if(top != -1 && *(stack + top) == '{') {
                top --;
            }
            else return false;
        }
        else stack[++top] = s[i];
    }
    if(top > -1) 
    return false;
    return true;
}
