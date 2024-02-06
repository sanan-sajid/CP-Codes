#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s)
{
    s->top = -1;
}

bool isEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, char value)
{
    if (s->top < MAX_SIZE - 1)
    {
        s->data[++s->top] = value;
    }
}

char pop(Stack *s)
{
    if (!isEmpty(s))
    {
        return s->data[s->top--];
    }
    return '\0'; // Stack is empty
}

bool isMatchingPair(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool isBalancedExpression(const char *expression)
{
    Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            push(&stack, expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            if (isEmpty(&stack) || !isMatchingPair(pop(&stack), expression[i]))
            {
                return false;
            }
        }
    }

    return isEmpty(&stack);
}

int main()
{
    char expression[MAX_SIZE];
    printf("Enter a parenthesized arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    if (isBalancedExpression(expression))
    {
        printf("Expression is properly parenthesized.\n");
    }
    else
    {
        printf("Expression is not properly parenthesized.\n");
    }

    return 0;
}