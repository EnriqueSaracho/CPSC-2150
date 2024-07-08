#include <iostream>
#include <vector>

void printHeap(std::vector<int>);
int removeTarget(std::vector<int> &, int);
void moveDown(std::vector<int> &, int);

int main()
{
    std::vector<int> heap = {3, 4, 5, 4, 7, 8};
    printHeap(heap);
    int deletions = removeTarget(heap, 3);
    std::cout << deletions << std::endl;
    printHeap(heap);
}

// TODO: Maybe counting all instances of target and creating a new list of all the items in the heap that are not target O(n)
// creating a heap out of that heap O(nlogn)
// total complexity O(nlogn)
int removeTarget(std::vector<int> &heap, int target)
{
    int del = 0;
    std::vector<int> clean;
    for (int i = 0; i < heap.size(); i++)
        if (heap[i] == target)
            del++;
        else
            clean.push_back(heap[i]);
    int i = (heap.size() - 2) / 2;
    moveDown(clean, i);
    heap = clean;
    return del;
}

void moveDown(std::vector<int> &heap, int first)
{
    int last = heap.size() - 1,
        min = 2 * first + 1;
    while (min <= heap.size() - 1)
    {
        if (min < last && heap[min] > heap[min + 1])
            min++;
        if (heap[first] > heap[min])
        {
            int temp = heap[first];
            heap[first] = heap[min];
            heap[min] = temp;

            first = min;
            min = 2 * first + 1;
        }
        else
            min = last + 1;
    }
}

void printHeap(std::vector<int> heap)
{
    int i = 0;
    std::cout << "[ ";
    for (; i < heap.size() - 1; i++)
        std::cout << heap[i] << ", ";
    std::cout << heap[i] << " ";
    std::cout << "]" << std::endl;
}
