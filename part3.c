#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (char*)malloc(capacity * sizeof(char));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, char item) {
    stack->top++;
    stack->data[stack->top] = item;
}

char pop(Stack* stack) {
    if (stack->top == -1) {
        return '\0';
    }
    char item = stack->data[stack->top];
    stack->top--;
    return item;
}

void freeStack(Stack* stack) {
    free(stack->data);
    free(stack);
}

int main() {
    // 单个字母表示字符串
    char letterStr[] = { 'k', 'i', 'g', 'l', 'n', 'm', 'r', 'm', 'e', 'i', 'a', 'h', 'e', 'n', 'r', 't', 'e', 'o', 'f', '4', 'a', 'r', 'd', 'a', 'r' };
    // 单个数字表示数字串
    int numStr[] = { 3,1,1,2,1 ,1,1 ,1 ,2,1 ,2 ,2 ,2 ,1,2 ,1,2 ,2 ,2 ,1,1 ,1 ,1 ,2,2 ,2 ,1,2 ,1 ,1,1 ,2 ,1 };

    Stack* stack = createStack(sizeof(letterStr));
    int letterIndex = 0;
    for (int numIndex = 0; numIndex < sizeof(numStr) / sizeof(numStr[0]); numIndex++) {
        int num = numStr[numIndex];
        if (numIndex % 2 == 0) {
            for (int j = 0; j < num && letterIndex < sizeof(letterStr) / sizeof(letterStr[0]); j++) {
                push(stack, letterStr[letterIndex++]);
            }
        }
        else {
            for (int j = 0; j < num; j++) {
                char popped = pop(stack);
                if (popped != '\0') {
                    printf("%c", popped);
                }
            }
        }
    }
    printf("\n");
    freeStack(stack);
    return 0;
}