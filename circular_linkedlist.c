#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element = %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct Node *insertAtLast(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}

struct Node *insertAfterNode(struct Node *head,struct Node*prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 45;
    second->next = third;

    third->data = 742;
    third->next = fourth;

    fourth->data = 331;
    fourth->next = head;

    printf("Before insertion\n");
    linkedListTraversal(head);

    // head = insertAtFirst(head, 95);
    // head = insertAtFirst(head, 950);
    // printf("\nAfter inserting element at the beginning\n");

    // head = insertAtIndex(head, 54, 2);
    // printf("\nAfter inserting element at the index\n");

    //head = insertAtLast(head, 100);
    //printf("\nAfter inserting element at the end\n");

    head = insertAfterNode(head, second, 200);
    printf("\nAfter inserting element after the node\n");
    linkedListTraversal(head);
    
    return 0;
}
