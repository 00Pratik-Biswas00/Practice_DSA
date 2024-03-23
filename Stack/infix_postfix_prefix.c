#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity) // create
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    return stack;
}

int isEmpty(struct Stack *stack) // empty
{
    return stack->top == -1;
}

char peek(struct Stack *stack) // peek
{
    return stack->array[stack->top];
}

char pop(struct Stack *stack) // pop
{
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack *stack, char op) // push
{
    stack->array[++stack->top] = op;
}

int isOperand(char ch) // operand
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Prec(char ch) // precedence
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}

int parenthesis(char *ptr) // parenthesis
{
    struct Stack *sp = createStack(strlen(ptr));

    for (int i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == '(')
            push(sp, '(');
        else if (ptr[i] == ')')
        {
            if (isEmpty(sp))
                return 0;
            pop(sp);
        }
    }
    if (isEmpty(sp))
        return 1;
    else
        return 0;
}

// infix to postfix

int infixToPostfix(char *exp)
{
    int i, k;

    struct Stack *stack = createStack(strlen(exp));
    if (!stack)
        return -1;

    for (i = 0, k = -1; exp[i]; ++i)
    {

        if (isOperand(exp[i]))
            exp[++k] = exp[i];

        else if (exp[i] == '(')
            push(stack, exp[i]);

        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
            {
                return -1;
                break;
            }
            else
                pop(stack);
        }

        else
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }

    while (!isEmpty(stack))
        exp[++k] = pop(stack);

    exp[++k] = '\0';
    return 1;
}

//  infix to prefix

void reverse(char s[]) // reverse
{
    int i, j;
    for (j = 0; s[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        int t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

void brackets(char *exp) // brackets
{
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
        i++;
    }
}

void infixToPrefix(char *exp)
{

    int size = strlen(exp);

    reverse(exp);

    brackets(exp);

    infixToPostfix(exp);

    reverse(exp);
}

// prefix to postfix
/*

void push(char c)
{
    stack[++top] = c;
}
char pop()
{
    return stack[top--];
}
*/

void prefixToPostfix(char *str)
{
    int n, i, j = 0, top = -1;
    char c[20], stack[50];
    char a, b, op;

    n = strlen(str);
    for (i = 0; i < 50; i++)
        stack[i] = '\0';

    for (i = 0; i < n; i++)
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            stack[++top] = str[i];
        }
        else
        {
            c[j++] = str[i];
            while ((top != -1) && (stack[top] == '@'))
            {
                a = stack[top--];
                c[j++] = stack[top--];
            }
            stack[++top] = '@';
        }
    }
    c[j] = '\0';
    printf("%s\n", c);
}

// main function

int main()
{

    printf("1. Infix to Postfix.\n2. Infix to Prefix.\n3. Prefix to Postfix.\n");
    char exp[50];
    printf("Enter the expression: ");
    scanf("%s", &exp);
    int p;
    printf("Enter the choice: ");
    scanf("%d", &p);

    if (parenthesis(exp))
    {
        switch (p)
        {
        case 1:
            infixToPostfix(exp);
            printf("%s\n", exp);
            break;
        case 2:
            infixToPrefix(exp);
            printf("%s\n", exp);
            break;
        case 3:
            prefixToPostfix(exp);
            break;

        default:
            printf("Wrong Choice\n");
            break;
        }
    }
    else
        printf("Parenthesis not matched\n");

    return 0;
}
