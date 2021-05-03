#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    size_t stackCapacity; /* number of elements the stack can contain */
    size_t numOfElems; /* number of elements are currently in the stack */
    int *data;
} Stack;

void printStack(Stack *myStack)
{
    if (myStack == NULL)
    {
        return;
    }

    for(size_t i = 0; i < myStack->numOfElems; ++i)
    {
        printf("%d, ", myStack->data[i]);
    }

    printf("\n");

    printf("numOfElems: %lu, stackCapacity: %lu\n",
           myStack->numOfElems, myStack->stackCapacity);
}

void deleteStack(Stack **myStack)
{
    if (*myStack == NULL)
    {
        return;
    }

    if ((*myStack)->data != NULL)
    {
        free((*myStack)->data);
    }
    free(*myStack);
    *myStack = NULL;
}

Stack *newStack(void)
{
    Stack *myStack = (Stack *) malloc(sizeof(Stack));
    myStack->data = (int *) malloc(sizeof(int));
    myStack->stackCapacity = 1;
    myStack->numOfElems = 0;
    return myStack;
}

void push(Stack *stack, int new_num) {
    if (stack != NULL) {
        int *temp = stack->data;

        for (int counter = 0; counter < stack->numOfElems; counter++) {
            temp++;
        }

        *(temp) = new_num;
        stack->numOfElems += 1;
        if (stack->numOfElems == stack->stackCapacity){
            stack->stackCapacity *= 2;
            stack->data = (int *) realloc(stack->data, sizeof(int)*stack->stackCapacity);
        }
    }
}

int pop(Stack *stack) {
    if (stack->numOfElems == 0) {
        return 0;
    }
    if (stack != NULL) {
        stack->data[(stack->numOfElems - 1)] = NULL;
        stack->numOfElems -= 1;
        if ((stack->stackCapacity) / (stack->numOfElems) >= 4) {
            stack->stackCapacity /= 2;
            stack->data = (int *) realloc(stack->data, sizeof(int)*stack->stackCapacity);
        }
        return 1;
    }
    return 0;
}

int main() {
    Stack *my_stack = newStack();
    push(my_stack, 1);
    push(my_stack, 2);
    push(my_stack, 3);
    push(my_stack, 4);
    pop(my_stack);
    pop(my_stack);
    printStack(my_stack);
}