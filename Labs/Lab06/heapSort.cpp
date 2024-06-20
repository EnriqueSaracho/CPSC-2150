#include <iostream>

void printList(int[], int);      // O(n)
void buildHeap(int[], int, int); // O(?)
int findMax(int, int, int);      // O(1)
int findMax(int, int);           // O(1)
void swap(int[], int, int);      // O(1)
void heapSort(int[], int);       // O(?)

int main()
{
    int n = 9;
    int *data = new int[n]{2, 8, 6, 1, 10, 15, 3, 12, 11};
    printList(data, n);

    heapSort(data, n);
    printList(data, n);

    delete[] data;
}

void printList(int data[], int n)
{
    int i = 0;
    std::cout << "[ ";
    for (; i < n - 1; i++)
        std::cout << data[i] << ", ";
    std::cout << data[i] << " ";
    std::cout << "]" << std::endl;
}

void buildHeap(int data[], int n, int i)
{
    int left = 2 * i + 1,
        right = 2 * i + 2,
        max,
        child = n;
    if (right < n)
        max = findMax(data[i], data[left], data[right]);
    else
        max = findMax(data[i], data[left]);
    if (max != data[i])
        if (max == data[left])
        {
            swap(data, i, left);
            child = left * 2 + 1;
        }
        else
        {
            swap(data, i, right);
            child = right * 2 + 1;
        }

    if (child < n)
    {
        int subroot = (child - 1) / 2;
        buildHeap(data, n, subroot);
    }
    return;
}

int findMax(int a, int b, int c)
{
    int max = a;
    if (a < b)
    {
        max = b;
        if (b < c)
            max = c;
    }
    else if (a < c)
        max = c;

    return max;
}

int findMax(int a, int b)
{
    int max = a;
    if (a < b)
        max = b;

    return max;
}

void swap(int data[], int i, int j)
{
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
    return;
}

void heapSort(int data[], int n)
{
    if (n > 1)
    {

        int i = (n - 2) / 2;
        for (; i > -1; i--) // O(logn)
            buildHeap(data, n, i);

        swap(data, 0, n - 1);
        heapSort(data, n - 1);
    }
    return;
}