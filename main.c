#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPRESSION_LENGTH 100

//stack for RPN
struct stack {
    char data[MAX_EXPRESSION_LENGTH];
    int top;
};

int is_argument(char c){
    return (c>='0' && c<='9');
}

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void rpn_init_stack(struct stack *s) {
    s->top = -1;
}

int rpn_is_stack_empty(struct stack *s) {
    return (s->top == -1);
}

void rpn_push(struct stack *s, char element) {
    if (s->top < MAX_EXPRESSION_LENGTH - 1) {
        s->data[++s->top] = element;
    }
}

char rpn_pop(struct stack *s) {
    if (!rpn_is_stack_empty(s)) {
        return s->data[s->top--];
    } else {
        return '\0';
    }
}

int rpn_get_operator_priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;  // default priority
}

int compute_postfix(char expr[])
{
    struct stack operatorStack;
    rpn_init_stack(&operatorStack);
    double result;
     for (int i = 0; expr[i] != '\0'; i++) {
        if(is_argument(expr[i])){
            rpn_push(&operatorStack,expr[i]);
        } else{
            char a_ = rpn_pop(&operatorStack);
            char b_ = rpn_pop(&operatorStack);
            int a = a_ - '0';
            int b = b_ - '0';
            switch(expr[i]){
                case '*':
                    result = a*b;
                    break;
                case '/':
                    result = a/b;
                    break;
                case '+':
                    result = a+b;
                    break;
                case '-':
                    result = a-b;
                    break;
                default:
                    printf("ERROR\n");
            }
            rpn_push(&operatorStack,'0'+result);
        }
     }
     printf("result: %0.2f\n",result);
     
     return (int)result;
}
void convert_to_postfix(char input[], char output[])
{
struct stack operatorStack;
    rpn_init_stack(&operatorStack);

    int rpnIndex = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char token = input[i];

        if (token == ' ') {
            continue;  // Ignoruj spacje
        } else if (isdigit(token) || isalpha(token)) {
            output[rpnIndex++] = token;
        } else if (is_operator(token)) {
            while (!rpn_is_stack_empty(&operatorStack) && rpn_get_operator_priority(operatorStack.data[operatorStack.top]) >= rpn_get_operator_priority(token)) {
                output[rpnIndex++] = rpn_pop(&operatorStack);
            }
            rpn_push(&operatorStack, token);
        } else if (token == '(') {
            rpn_push(&operatorStack, token);
        } else if (token == ')') {
            while (!rpn_is_stack_empty(&operatorStack) && operatorStack.data[operatorStack.top] != '(') {
                output[rpnIndex++] = rpn_pop(&operatorStack);
            }
            if (!rpn_is_stack_empty(&operatorStack) && operatorStack.data[operatorStack.top] == '(') {
                rpn_pop(&operatorStack);  // Usuń '(' ze stosu
            }
        }
    }

    while (!rpn_is_stack_empty(&operatorStack)) {
        output[rpnIndex++] = rpn_pop(&operatorStack);
    }

    output[rpnIndex] = '\0';

    printf("Conversion result to RPN: %s\n", output);
    
}

int main()
{
    int input_ptr = 0;

    char str[MAX_EXPRESSION_LENGTH]; // 
    printf("Enter a math equation: ");
    scanf("%s", str); // Odczytaj łańcuch znaków od użytkownika

    printf("Mathematical equation introduced: %s\n", str); // Wyświetl odczytany łańcuch

    char rpn_str[MAX_EXPRESSION_LENGTH];

    convert_to_postfix(str,rpn_str);

    compute_postfix(rpn_str);

    return 0;
}