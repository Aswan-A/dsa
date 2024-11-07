#include <stdio.h>
#include<string.h>
#include <stdlib.h>

struct Node {
    char model[20];
    int price;
    char manuf[20];
    double cap;
    struct Node* prev;
    struct Node* next;
};
typedef struct Node Node;

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void enqFront(Node** head, char model[], int price, char manuf[], double cap){
    Node* newNode = createNode();
    strcpy(newNode->model, model);
    newNode->price = price;
    strcpy(newNode->manuf, manuf);
    newNode->cap = cap;
    if(*head == NULL){
        *head = newNode;
    } else {
        (*head)->prev = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void enqRear(Node** head, char model[], int price, char manuf[], double cap){
    Node* newNode = createNode();
    strcpy(newNode->model, model);
    newNode->price = price;
    strcpy(newNode->manuf, manuf);
    newNode->cap = cap;
    if(*head == NULL){
        *head = newNode;
    } else {
        Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }
}

void deqFront(Node** head){
    if(*head == NULL){
        printf("Dequeue is empty");
    } else if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
        printf("Dequeued successfully");
    } else {
        Node* temp = (*head)->next;
        temp->prev = NULL;
        free(*head);
        *head = temp;
        printf("Dequeued successfully");
    }
}

void deqRear(Node** head){
    if(*head == NULL){
        printf("Dequeue is empty");
        return;
    } else if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
        printf("Dequeued successfully");
        return;
    }
    Node* temp = *head;
    Node* prevTemp = *head;
    while(temp->next != NULL){
        prevTemp = temp;
        temp = temp->next;
    }
    prevTemp->next = NULL;
    free(temp);
    printf("Dequeued successfully");
}

void printAll(Node* head) {
    int count = 1;
    if(head == NULL){
        printf("NULL");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("\nItem No: %d",count);
        printf("\nPrice: %d", temp->price);
        printf("\nManufacturer: %s", temp->manuf);
        printf("\nCapacity: %f\n", temp->cap);
        temp = temp->next;
        count++;
    }
    printf("NULL");
}
void updatePrice(Node** head, int pos){
	int newPrice;
	printf("Enter the new price of the model: ");
	scanf("%d", &newPrice);

	Node* temp = *head;
	for (int i = 1; i < pos; i++) {
		if (temp == NULL) {
			printf("Exceeded Bounds of List\n");
			return ;
		}
		temp = temp->next;
	}
	temp -> price = newPrice;
	printf("\nPrice updated");
}

void searchPriceRange(Node** head) {
	if(*head == NULL){
		printf("List is Empty\n");
		return;
	}
	int lowPrice, upPrice;
	printf("Enter lower bound of price: ");
	scanf("%d", &lowPrice);
	printf("Enter upper bound of price: ");
	scanf("%d", &upPrice);
	Node* temp;
	temp = *head;
	while(temp!=NULL) {
		if(temp -> price > lowPrice && temp -> price < upPrice){
			printf("\n%s\n", temp -> model);
			printf("%d\n", temp -> price);
			printf("%s\n", temp -> manuf);
			printf("%f\n", temp-> cap);
			printf("-----------------------------");
		}
		temp = temp->next;
	}
	printf("\n");
}
void searchmodel(Node** head) {
	char name[20];
	printf("Enter name of Model to search: ");
	scanf(" %[^\n]s", name);

	Node* temp;
	temp = *head;
	while(temp!=NULL) {
		if(strcmp(temp -> model, name) == 0) {
			printf("\n%s\n", temp -> model);
			printf("%d\n", temp -> price);
			printf("%s\n", temp -> manuf);
			printf("%lf\n", temp-> cap);
			printf("-----------------------------");
		}
		temp = temp->next;
	}
	printf("\n");
}

void main() {
    int ch,data,c;
    Node* head = NULL;
    while(1){
        printf("\nOptions");
        printf("\n1.Insert car information");
        printf("\n2.Delete a particular model");
        printf("\n3.Update price");
        printf("\n4.List of cars within a price range");
        printf("\n5.Check for a model");
        printf("\n6.Display all items");
        printf("\n7.Exit");
        printf("\nEnter your choice(1-6):");
        scanf("%d",&ch);
        switch(ch){
            case 1:
              char model[20],manuf[20];
              int price;
              double cap;
              printf("\nEnter the model: ");
              scanf("%s",model);
              printf("\nEnter the price: ");
              scanf("%d",&price);
              printf("\nEnter the manufacturer: ");
              scanf("%s",manuf);
              printf("\nEnter the engine capacity: ");
              scanf("%lf",&cap);
              printf("\nEnter a insertion option:");
              printf("\n1.Front");
              printf("\n2.Rear");
              printf("\nEnter your choice(1/2): ");
              scanf("%d",&c);
              switch(c){
                  case 1:
                  enqRear(&head,model,price,manuf,cap);
                  break;
                  
                  case 2:
                  enqRear(&head,model,price,manuf,cap);
                  break;
              }
              break;
            
            case 2:
              printf("\nEnter deletion option");
              printf("\n1.Delete at front");
              printf("\n2.Delete at rear");
              printf("\nEnter choice(1/2): ");
              scanf("%d",&c);
              switch(c){
                  case 1:
                  deqFront(&head);
                  break;
                  
                  case 2:
                  deqRear(&head);
                  break;
              }
              break;
              
            case 3:
              printf("\nEnter the position: ");
              scanf("%d",&data);
              updatePrice(&head, data);
              break;
              
            case 4:
              searchPriceRange(&head);
              break;
              
            case 5:
              searchmodel(&head);
	          break;
	          
	        case 6:
	          printAll(head);
	          break;
              
            default:
              return;
        }
    }
}
