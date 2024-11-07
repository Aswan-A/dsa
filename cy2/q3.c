#include <stdio.h>
#include <stdlib.h>

 struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};


struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertTerm(struct Node* head, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);

    if (!head || head->exponent < exponent) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    while (temp->next && temp->next->exponent > exponent) {
        temp = temp->next;
    }

    if (temp->exponent == exponent) {
        temp->coefficient += coefficient;
       
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 && p2) {
        if (p1->exponent == p2->exponent) {
            result = insertTerm(result, p1->coefficient + p2->coefficient, p1->exponent);
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->exponent > p2->exponent) {
            result = insertTerm(result, p1->coefficient, p1->exponent);
            p1 = p1->next;
        } else {
            result = insertTerm(result, p2->coefficient, p2->exponent);
            p2 = p2->next;
        }
    }

    while (p1) {
        result = insertTerm(result, p1->coefficient, p1->exponent);
        p1 = p1->next;
    }

    while (p2) {
        result = insertTerm(result, p2->coefficient, p2->exponent);
        p2 = p2->next;
    }

    return result;
}

struct Node* multiplyPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    for (struct Node* t1 = p1; t1 != NULL; t1 = t1->next) {
        struct Node* temp = NULL;
        for (struct Node* t2 = p2; t2 != NULL; t2 = t2->next) {
            temp = insertTerm(temp, t1->coefficient * t2->coefficient, t1->exponent + t2->exponent);
        }
        result = addPolynomials(result, temp);
    }

    return result;
}

void printPolynomial(struct Node* head) {
    while (head) {
        printf("%dx^%d", head->coefficient, head->exponent);
        head = head->next;
        if (head)
            printf(" + ");
    }
    printf("\n");
}

struct Node* inputPolynomial() {
    struct Node* head = NULL;
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int coeff, exp;
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        head = insertTerm(head, coeff, exp);
    }

    return head;
}

int main() {
    printf("Input the first polynomial:\n");
    struct Node* poly1 = inputPolynomial();

    printf("Input the second polynomial:\n");
    struct Node* poly2 = inputPolynomial();

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    struct Node* sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    printPolynomial(sum);

    struct Node* product = multiplyPolynomials(poly1, poly2);
    printf("Product: ");
    printPolynomial(product);

    return 0;
}