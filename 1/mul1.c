#include <stdio.h>


int MAX_DEGREE = 100;


void multiplyPolynomials(int A[], int B[], int m, int n, int result[]) {

    for (int i = 0; i < m + n - 1; i++) {
        result[i] = 0;
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[i + j] += A[i] * B[j];
        }
    }
}

void printPolynomial(int poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i], i);
        if (i != n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    int A[MAX_DEGREE + 1], B[MAX_DEGREE + 1], result[2 * MAX_DEGREE + 1];
    int m, n;

    printf("Enter the degree of polynomial A (max %d): ", MAX_DEGREE);
    scanf("%d", &m);
    m++; 
    printf("Enter the coefficients for polynomial A:\n");
    for (int i = 0; i < m; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &A[i]);
    }


    printf("Enter the degree of polynomial B (max %d): ", MAX_DEGREE);
    scanf("%d", &n);
    n++;

    printf("Enter the coefficients for polynomial B:\n");
    for (int i = 0; i < n; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &B[i]);
    }


    multiplyPolynomials(A, B, m, n, result);


    printf("Resultant polynomial: ");
    printPolynomial(result, m + n - 1);

    return 0;
}
