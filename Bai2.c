#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không th? c?p phát b? nh?\n");
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

// Ham chen phan tu vao dau
void insertHead(Node** head, int value){
	// Tao node moi
	Node* newNode = createNode(value);
	
	// Tro node moi den head
	newNode->next = *head;
	
	// Cap nhat head tro den node moi
	*head = newNode;
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
	int value;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);
	
	int arr[n];

	for(int i=0; i<n; i++){
		printf("arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}
	head = createList(arr, n);

    printf("Danh sach lien ket ban dau: \n");
    printList(head);

	printf("Nhap gia tri can chen: ");
	scanf("%d", &value);
	
	insertHead(&head, value);
	
	printf("Danh sach lien ket sau khi cap nhat: \n");
	printList((head));
	
    return 0;
}
