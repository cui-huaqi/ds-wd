#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define STACK_SIZE 100

typedef struct {
    int data[STACK_SIZE];
    int min[STACK_SIZE];
    int top;
} MinStack;

void minStackInit(MinStack *ms) {
    ms->top = -1;
}

int minStackPush(MinStack *ms, int x) {
    if (ms->top >= STACK_SIZE - 1) {
        return 0; // 栈满
    }
    
    ms->data[++ms->top] = x;
    if (ms->top == 0 || x < ms->min[ms->top - 1]) {
        ms->min[ms->top] = x;
    } else {
        ms->min[ms->top] = ms->min[ms->top - 1];
    }
    
    return 1;
}

int minStackPop(MinStack *ms) {
    if (ms->top < 0) {
        return INT_MIN; // 栈空
    }
    
    int x = ms->data[ms->top--];
    ms->min[ms->top + 1] = INT_MAX;
    
    return x;
}

int minStackTop(MinStack *ms) {
    if (ms->top < 0) {
        return INT_MIN; // 栈空
    }
    
    return ms->data[ms->top];
}

int minStackGetMin(MinStack *ms) {
    if (ms->top < 0) {
        return INT_MIN; // 栈空
    }
    
    return ms->min[ms->top];
}

int main() {
    MinStack ms;
    minStackInit(&ms);
    
    minStackPush(&ms, 3);
    minStackPush(&ms, 2);
    minStackPush(&ms, 4);
    minStackPush(&ms, 1);
    
    printf("%d\n", minStackGetMin(&ms)); // 输出1
    
    minStackPop(&ms);
    minStackPop(&ms);
    
    printf("%d\n", minStackGetMin(&ms)); // 输出2
    
    minStackPush(&ms, 0);
    minStackPush(&ms, 2);
    
    printf("%d\n", minStackGetMin(&ms)); // 输出0
    
    return 0;
}