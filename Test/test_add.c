#include <stdio.h>
int printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int new_begin(int arr[], int size, int newElement1)
{
    for (int i = size; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = newElement1;
    return size + 1;
}
int new_mid(int arr[], int size, int newElement, int pos)
{
    if (pos < 0 || pos > size)
    {
        printf("Invalid position!\n");
        return size;
    }
    for (int i = size; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = newElement;
    return size + 1;
}
int new_end(int arr[], int size, int newElement3)
{
    arr[size] = newElement3;
    return size + 1;
}
int main()
{
    int size, i, arr[100];
    int newElement1, newElement2, newElement3;
    int pos;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements: ");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    // Display original array
    printf("Original array: ");
    printArray(arr, size);

    // To add new element in the beginning of the array
    printf("\nEnter NEW elements to add at the START: ");
    scanf("%d", &newElement1);
    size = new_begin(arr, size, newElement1);
    printf("New array: ");
    printArray(arr, size);

    // To add new element in the middle of the array
    printf("\nEnter NEW element to add in the MIDDLE: ");
    scanf("%d", &newElement2);
    printf("Enter position (0 to %d): ", size);
    scanf("%d", &pos);
    size = new_mid(arr, size, newElement2, pos);
    printf("Array after inserting at position %d: ", pos);
    printArray(arr, size);

    // To add new element at the end of the array
    printf("\nEnter NEW element to add in the END: ");
    scanf("%d", &newElement3);
    size = new_end(arr, size, newElement3);
    printf("Array after inserting at end: ");
    printArray(arr, size);
    return 0;
}