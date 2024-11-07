#include <stdio.h>
#include <stdbool.h>
#define MAX 100


bool isValidExpression(const char *expr);
bool isEmpty();
char top();
void push(char c, int index);
char pop();
bool isMatchingPair(char open, char close);
int findClosingIndex(const char *expr, int openIndex);

typedef struct {
    char bracket;
    int index;
} StackElement;

StackElement stack[MAX];
int topIndex = -1;

int main() {
    char expression[MAX];
    int openIndex;

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (isValidExpression(expression)) {
        printf("The expression has balanced parentheses.\n");
    } else {
        printf("The expression does not have balanced parentheses.\n");
        return 0;
    }

    printf("Enter the index of the opening bracket to find its closing bracket: ");
    scanf("%d", &openIndex);

    int closingIndex = findClosingIndex(expression, openIndex);
    if (closingIndex != -1) {
        printf("The closing bracket for the opening bracket at index %d is at index %d.\n", openIndex, closingIndex);
    } else {
        printf("No matching closing bracket found for the opening bracket at index %d.\n", openIndex);
    }

    return 0;
}

bool isValidExpression(const char *expr) {
    int index = 0;
    while (expr[index]) {
        char c = expr[index];

        if (c == '(' || c == '{' || c == '[') {
            push(c, index);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty()) {
                return false;
            }
            char topChar = pop();
            if (!isMatchingPair(topChar, c)) {
                return false;
            }
        }
        index++;
    }

    return isEmpty();
}

bool isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

bool isEmpty() {
    return topIndex == -1;
}

void push(char c, int index) {
    if (topIndex >= MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        stack[++topIndex].bracket = c;
        stack[topIndex].index = index;
    }
}

char pop() {
    if (isEmpty()) {
        return '\0';
    }
    return stack[topIndex--].bracket;
}

int findClosingIndex(const char *expr, int openIndex) {
    topIndex = -1;  
    int index = 0;
    while (expr[index]) {
        char c = expr[index];

        if (c == '(' || c == '{' || c == '[') {
            push(c, index);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty()) {
                return -1;  
            }
            if (stack[topIndex].index == openIndex) {
                return index;  
            }
            pop();
        }
        index++;
    }

    return -1; 
}
