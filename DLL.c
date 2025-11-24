#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

// ---- Create / Insert at End ----
void create(int value) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->prev = newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

// ---- Insert to Left of a Given Value ----
void insertLeft(int target, int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("\nValue %d not found!", target);
        return;
    }

    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;

    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode; // inserting before the first node

    temp->prev = newnode;
}

// ---- Delete Node by Value ----
void deleteValue(int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("\nValue %d not found!", value);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next; // deleting first node

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// ---- Display List ----
void display() {
    struct Node *temp = head;
    printf("\nList: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, value, target;

    while (1) {
        printf("\n\n--- MENU ---");
        printf("\n1. Create/Insert at End");
        printf("\n2. Insert to Left of a Node");
        printf("\n3. Delete by Value");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                create(value);
                break;

            case 2:
                printf("Enter target value: ");
                scanf("%d", &target);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertLeft(target, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
        }
    }
}
