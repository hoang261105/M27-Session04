#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phát bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* createList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = createNode(arr[0]); 
    Node* current = head;

    for (int i = 1; i < n; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    return head;
}

void insertElement(Node** head, int value, int position){
	Node* newNode = createNode(value);
	
	if(position == 0){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	
	Node* temp = *head;
	for(int i=0; i<position - 1 && temp != NULL; i++){
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}


void printList(Node* head){
	Node* temp = head;
	while(temp != NULL){
		printf("%d --> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main(){
	Node* head = NULL;
	
	int n;
	int position, value;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	
	int arr[n];

	for(int i=0; i<n; i++){
		printf("arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}
	head = createList(arr, n);

    printf("Danh sach lien ket: \n");
    printList(head);
    
    printf("Nhap vi tri can chen: ");
    scanf("%d", &position);
    
    printf("Nhap gia tri chen: ");
    scanf("%d", &value);
    
    insertElement(&head, value, position);
    printf("Danh sach lien ket sau khi cap nhat: \n");
    printList(head);

    return 0;
}
