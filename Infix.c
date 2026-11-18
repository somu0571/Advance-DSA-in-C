#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[100];
    char *e;
    int n1, n2, num;
    printf("Enter postfix expression to evaluate: ");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0') {
        if (isdigit(*e)) {
            num = *e - 48;
            push(num);
        } else {
            n2 = pop();
            n1 = pop();
            switch (*e) {
                case '+': push(n1 + n2); break;
                case '-': push(n1 - n2); break;
                case '*': push(n1 * n2); break;
                case '/': push(n1 / n2); break;
            }
        }
        e++;
    }
    printf("The result of evaluation = %d\n", pop());
    return 0;
}