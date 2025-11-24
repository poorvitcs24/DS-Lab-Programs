#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* insertEnd(struct Node *head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}
void display(struct Node *head) {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
struct Node* copyList(struct Node *head) {
    struct Node *newHead = NULL;
    struct Node *temp = head;

    while (temp != NULL) {
        newHead = insertEnd(newHead, temp->data);
        temp = temp->next;
    }
    return newHead;
}
void sortList(struct Node *head) {
    if (head == NULL) {
        printf("List empty, cannot sort.\n");
        return;
    }

    struct Node *sorted = copyList(head);

    struct Node *i, *j;
    int temp;

    for (i = sorted; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("Sorted List: ");
    display(sorted);
}
void reverseList(struct Node *head) {
    if (head == NULL) {
        printf("List empty, cannot reverse.\n");
        return;
    }

    struct Node *rev = NULL;
    struct Node *temp = head;

    while (temp != NULL) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = temp->data;
        newNode->next = rev;
        rev = newNode;

        temp = temp->next;
    }

    printf("Reversed List: ");
    display(rev);
}
void concatenateLists(struct Node *head1, struct Node *head2) {
    if (head1 == NULL && head2 == NULL) {
        printf("Both lists empty. Cannot concatenate.\n");
        return;
    }

    struct Node *newList = NULL;

    struct Node *temp = head1;
    while (temp != NULL) {
        newList = insertEnd(newList, temp->data);
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL) {
        newList = insertEnd(newList, temp->data);
        temp = temp->next;
    }

    printf("Concatenated List: ");
    display(newList);
}
int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, value;

    while (1) {
        printf("\n---- MENU ----\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Sort List 1 (new list)\n");
        printf("4. Reverse List 1 (new list)\n");
        printf("5. Concatenate List1 + List2 (new list)\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                list1 = insertEnd(list1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                list2 = insertEnd(list2, value);
                break;

            case 3:
                sortList(list1);
                break;

            case 4:
                reverseList(list1);
                break;

            case 5:
                concatenateLists(list1, list2);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
