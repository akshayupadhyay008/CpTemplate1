#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* first;

void createLinkedList(int arr[], int num) {

    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));

    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < num; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void displayLinkedList(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {

    int num;
    printf("Enter the number of data you want to input : ");
    scanf("%d",&num);

    int arr[num];

    for(int i=0;i<num;i++) {
        scanf("%d",&arr[i]);
    }

    createLinkedList(arr, num);

    displayLinkedList(first);

    return 0;
}