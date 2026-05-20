#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert_begin(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != head)
        temp = temp->next;
    newnode->next = head;
    temp->next = newnode;
    head = newnode;
}

void insert_end(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    if (head == NULL)
    {
        newnode->next = newnode;
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newnode;
    newnode->next = head;
}

void insert_pos(int data, int pos)
{
    struct node *newnode, *temp;
    int i;
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data = data;
    if (pos == 1)
    {
        if (head == NULL)
        {
            newnode->next = newnode;
            head = newnode;
            return;
        }
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
        return;
    }
    temp = head;
    for (i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (i != pos - 1)
    {
        printf("Invalid position\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_begin()
{
    struct node *temp, *last;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->next == head)
    {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    last = head;
    while (last->next != head)
        last = last->next;
    temp = head;
    head = head->next;
    last->next = head;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void delete_end()
{
    struct node *temp, *prev;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (head->next == head)
    {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    prev = NULL;
    temp = head;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void delete_pos(int pos)
{
    struct node *temp = head, *deletenode;
    int i;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1)
    {
        delete_begin();
        return;
    }
    for (i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (temp->next == head)
    {
        printf("Invalid position\n");
        return;
    }
    deletenode = temp->next;
    temp->next = deletenode->next;
    printf("Deleted element: %d\n", deletenode->data);
    free(deletenode);
}

void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Circular Singly Linked List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

void status()
{
    struct node *temp;
    int count = 0;
    if (head == NULL)
    {
        printf("List is empty\n");
        printf("Number of nodes: 0\n");
        return;
    }
    temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    printf("List is not empty\n");
    printf("Number of nodes: %d\n", count);
}

int main()
{
    int choice, data, pos;
    while (1)
    {
        printf("\n1. Insert at begin\n2. Insert at end\n3. Insert at position\n4. Delete at begin\n5. Delete at end\n6. Deletion at position\n7. Status and count\n8. Display\n9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_begin(data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insert_end(data);
            break;
        case 3:
            printf("Enter data: ");
            scanf("%d", &data);

            printf("Enter position: ");
            scanf("%d", &pos);

            insert_pos(data, pos);
            break;
        case 4:
            delete_begin();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);

            delete_pos(pos);
            break;
        case 7:
            status();
            break;
        case 8:
            display();
            break;
        case 9:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}