#include <stdio.h>
int printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int del_begin(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        arr[i] = arr[i + 1]; // shift elements left
    return size - 1;
}
int del_mid(int arr[], int size, int pos)
{
    if (pos < 0 || pos >= size)
    {
        printf("Invalid position!\n");
        return size; // size unchanged
    }
    for (int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1]; // shift left
    return size - 1;         // new size
}
int del_end(int arr[], int size)
{
    if (size <= 0)
    {
        printf("Array is empty!\n");
        return size;
    }
    return size - 1;
}
int main()
{
    int size, i, arr[100], pos;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements: ");
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    // Display original array
    printf("Original array: ");
    printArray(arr, size);

    // Deleting first element
    size = del_begin(arr, size);
    printf("Array after deleting first element: ");
    printArray(arr, size);

    // Deleting element of any position
    printf("Enter position to delete (0-based index): ");
    scanf("%d", &pos);
    pos = pos - 1;
    size = del_mid(arr, size, pos);
    printf("Array after deletion: ");
    printArray(arr, size);

    // Deleting last element
    size = del_end(arr, size);
    printf("Array after deleting last element: ");
    printArray(arr, size);
    return 0;
}