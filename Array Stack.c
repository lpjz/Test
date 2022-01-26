#include <stdio.h>
#define SIZE 5
int stack[SIZE], top = -1;
void push(int value)
{
    if (top == SIZE - 1)
    {
        printf("Stack is Full!!");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}
void pop()
{
    if (top == -1)
        printf("\n Stack is Empty!!");
    else
    {
        stack[top] = -1;
        top--;
    }
}
int main()
{
    push(1);
    push(2);
    push(5);
    push(12);
    push(15);

    for (int i = 0; i < 5; i++)
        printf("%d\t", stack[i]);
    printf("\n\n");

    pop();
    for (int i = 0; i < 5; i++)
        printf("%d\t", stack[i]);

    getch();
    return 0;
}
