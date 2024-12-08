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

Node* reverseList(Node* head) {
    Node* prev = NULL;   
    Node* current = head; 
    Node* next = NULL;    

    while (current != NULL) {
        next = current->next;  
        current->next = prev;   
        prev = current;         
        current = next;         
    }

    return prev;
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
    
    head = reverseList(head);
    printf("Danh sach lien ket dao nguoc: \n");
    printList(head);

    return 0;
}
