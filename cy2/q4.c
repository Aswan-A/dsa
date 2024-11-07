#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void create(int a) {
    struct node* newnode;
    struct node* temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = a;
    newnode->next = NULL;
    
    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display() {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void swap(int p, int q) {
    if (p == q) return; 

    struct node *prevP = NULL, *currP = head;
    struct node *prevQ = NULL, *currQ = head;

    int count = 0;
    while (currP != NULL && count != p) {
        prevP = currP;
        currP = currP->next;
        count++;
    }

    count = 0;
    while (currQ != NULL && count != q) {
        prevQ = currQ;
        currQ = currQ->next;
        count++;
    }

    if (currP == NULL || currQ == NULL) {
        printf("Index out of bound\n");
        return;
    }

    if (prevP != NULL) {
        prevP->next = currQ;
    } else {
        head = currQ;
    }

    if (prevQ != NULL) {
        prevQ->next = currP;
    } else {
        head = currP;
    }

    struct node* temp = currQ->next;
    currQ->next = currP->next;
    currP->next = temp;
}

int main() {
    int n, a, p, q;
    while (1) {
        printf("\n1-create 2-display 3-swap 4-exit : ");
        scanf("%d", &n);

        if (n == 1) {
            printf("Enter your data: ");
            scanf("%d", &a);
            create(a);
        } else if (n == 2) {
            display();
        } else if (n == 3) {
            printf("Enter indices to swap: ");
            scanf("%d %d", &p, &q);
            swap(p, q);
        } else if (n == 4) {
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}