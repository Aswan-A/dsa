#include <stdio.h>
typedef struct {
    int coef;
    int exp;
} Term;
void add(Term p1[], int n1, Term p2[], int n2, Term result[], int *size);
void multiply(Term p1[], int n1, Term p2[], int n2, Term result[], int *size);
void printpoly(Term poly[], int size);

int main() {
   int c;
   while (1){
   printf("\n1-addition \n2-multiplication \n3-exit\n");
   scanf("%d",&c);
   if(c==3){
    break;}
    else if(c > 3){
    printf("InValid choice");}

    int n1, n2;
    printf("Number of elements: ");
    scanf("%d", &n1);
 

    Term pol1[100], pol2[100];
    printf("coeff   exp\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &pol1[i].coef, &pol1[i].exp);
    }
   
    printf("Number of elements: ");
    scanf("%d", &n2);
    printf("coeff   exp\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &pol2[i].coef, &pol2[i].exp);
    }
    if (c==1){
    Term addResult[100];
    int addResultSize;
    add(pol1, n1, pol2, n2, addResult, &addResultSize);
    printf("Sum: ");
    printpoly(addResult, addResultSize);
     }
     else if(c==2){
    Term mulResult[100];
    int mulResultSize;
    multiply(pol1, n1, pol2, n2, mulResult, &mulResultSize);
    printf("Product: ");
    printpoly(mulResult, mulResultSize);
    }
   
   
    }
    return 0;
}

void add(Term p1[], int n1, Term p2[], int n2, Term result[], int *size) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (p1[i].exp > p2[j].exp) {
            result[k++] = p1[i++];
        } else if (p1[i].exp < p2[j].exp) {
            result[k++] = p2[j++];
        } else {
            result[k].exp = p1[i].exp;
            result[k++].coef = p1[i++].coef + p2[j++].coef;
        }
    }

    while (i < n1) result[k++] = p1[i++];
    while (j < n2) result[k++] = p2[j++];

    *size = k;
}

void multiply(Term p1[], int n1, Term p2[], int n2, Term result[], int *size) {
    Term temp[100] = {0};
    int tempSize = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            int k;
            for (k = 0; k < tempSize; k++) {
                if (temp[k].exp == p1[i].exp + p2[j].exp) {
                    temp[k].coef += p1[i].coef * p2[j].coef;
                    break;
                }
            }
            if (k == tempSize) {
                temp[tempSize].coef = p1[i].coef * p2[j].coef;
                temp[tempSize].exp = p1[i].exp + p2[j].exp;
                tempSize++;
            }
        }
    }
    int k = 0;
    for (int i = 0; i < tempSize; i++) {
        int coefSum = temp[i].coef;
        int exp = temp[i].exp;
        if (coefSum != 0) {
            result[k].coef = coefSum;
            result[k++].exp = exp;
        }
    }

    *size = k;
}

void printpoly(Term poly[], int size) {
    int started = 0;

    for (int i = 0; i < size; i++) {
        if (poly[i].coef != 0) {
            if (started) {
                printf(" + ");
            }
            if (poly[i].exp == 0) {
                printf("%d", poly[i].coef);
            } else if (poly[i].exp == 1) {
                printf("%dx", poly[i].coef);
            } else {
                printf("%dx^%d", poly[i].coef, poly[i].exp);
            }
            started = 1;
        }
    }
    printf("\n");
}