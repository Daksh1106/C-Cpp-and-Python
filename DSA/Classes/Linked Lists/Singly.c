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
    if (newnode == NULL)
    {
        printf("Memory allocation failed");
        return;
    }
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insert_end(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    if (newnode == NULL)
    {
        printf("Memory allocation failed");
        return;
    }
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
}

void insert_pos(int data, int pos)
{
    struct node *newnode, *temp;
    int i;
    if (pos < 1)
    {
        printf("Invalid position");
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed");
        return;
    }
    newnode->data = data;
    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }
    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Invalid position");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_begin()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    head = head->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

void delete_end()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    if (head->next == NULL)
    {
        printf("Deleted element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    while (temp->next->next != NULL)
        temp = temp->next;
    printf("Deleted element: %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void delete_pos(int pos)
{
    struct node *temp = head;
    int i;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    if (pos == 1)
    {
        head = head->next;
        printf("Deleted element: %d\n", temp->next);
        free(temp);
        return;
    }
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }
    struct node *deletenode = temp->next;
    temp->next = deletenode->next;
    printf("Deleted element: %d\n", deletenode->data);
    free(deletenode);
}

void search(int key)
{
    struct node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element: %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found\n", key);
}

void display()
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, data, pos, key;
    while (1)
    {
        printf("1. Insert at begin\n2. Insert at end\n3. Insert at positon\n4. Delete at begin\n5. Delete at end\n6. Delete at pos\n7.Display\n8. Search a node\n9. Exit\n");
        printf("Enter choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data:");
            scanf("%d", &data);
            insert_begin(data);
            break;
        case 2:
            printf("Enter data:");
            scanf("%d", &data);
            insert_end(data);
            break;
        case 3:
            printf("Enter data:");
            scanf("%d", &data);
            printf("Enter position:");
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
            printf("Enter position:");
            scanf("%d", &pos);
            delete_pos(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Enter element to search: ");
            scanf("%d", &key);
            search(key);
            break;
        case 9:
            printf("Exiting...");
            exit(0);
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}