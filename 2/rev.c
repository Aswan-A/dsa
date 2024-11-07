
#include <stdio.h>
#include <string.h>
void reverseString(char s[]);
void main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
}

void reverseString(char s[]) {
    int length = strlen(s);
    int i = 0;
    int j = length - 1;
    char temp;
    while (i < j) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        i++;
        j--;
    }
}



