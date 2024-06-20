#include <iostream>

void printArray(int[], int);
int *heapTopDown(int[], int);

int main()
{
    int data[] = {2, 8, 6, 1, 10, 15, 3};
    printArray(data, 7);
}

int *heapTopDown(int data[], int size)
{
    int *heap = new int[size];
    int i = 0;
    heap[i] = data[i];
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}