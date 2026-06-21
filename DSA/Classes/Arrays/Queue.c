#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX], front = 0, rear = -1;
void insert_rear(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    queue[++rear] = value;
    printf("Inserted element: %d\n", value);
}

void insert_front(int value)
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    for (int i = rear; i >= front; i--)
        queue[i + 1] = queue[i];
    queue[front] = value;
    rear++;
    printf("Inserted element: %d\n", value);
}
void delete_front()
{
    if (front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    int value = queue[front++];
    printf("Deleted element: %d\n", value);
}
void delete_rear()
{
    if (front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    int value = queue[rear--];
    printf("Deleted element: %d\n", value);
}
void status()
{
    if (front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    else if(rear== MAX-1)
    {
        printf("Queue is full\n");
        return;
    }
    else
    {
        printf("Queue is neither full nor empty\n");
        return;
    }
}
void display()
{
    if (front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n1. Insert at rear\n 2. Insert at front\n 3. Delete from front\n 4. Delete from rear\n 5. Display queue\n 6. Check status\n 7. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to insert at rear: ");
            scanf("%d", &value);
            insert_rear(value);
            break;
        case 2:
            printf("Enter element to insert at front: ");
            scanf("%d", &value);
            insert_front(value);
            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            status();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}