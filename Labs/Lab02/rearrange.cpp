#include <iostream>
#include <string>

/**
 * PrintArray function:
 * prints dynamic array of strings
 *
 * @param arr - pointer to dynamic array
 * @param n - integer, amount of keys in array
 * @return void, message to the console.
 */
void printArray(std::string *arr, int n);

/**
 * rearrange function:
 * rearranges arrays keys in the order: red > blue > white
 *
 * @param arr - pointer to dynamic array
 * @param n - integer, amount of keys in array
 * @return void, rearranged array.
 */
void rearrange(std::string *arr, int n);

/**
 * swap:
 * swaps two values from a dynamic array based on their indices.
 *
 * @param arr - pointer to dynamic array
 * @param t - integer, tracks the index of next key from the last change
 * @param i - integer, looks for the next key to swap
 */
void swap(std::string *arr, int t, int i);

/**
 * main function
 */
int main()
{
    std::string *arr = new std::string[10]{"blue", "red", "white", "white", "blue", "white", "red", "blue", "white", "red"};
    int n = 10;

    std::cout << std::endl;
    std::cout << "Before rearrange algorithm:" << std::endl;
    printArray(arr, n);

    rearrange(arr, n);

    std::cout << "After rearrange algorithm:" << std::endl;
    printArray(arr, n);
    std::cout << std::endl;
}

// Function definitions
void printArray(std::string *arr, int n)
{
    int i = 0;
    std::cout << "[ ";
    for (; i < n - 1; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[i] << " ]" << std::endl;
}

void rearrange(std::string *arr, int n)
{
    int t = 0,
        i = 0;

    for (; i < n; i++)
        if (arr[i] == "red")
        {
            swap(arr, t, i);
            t++;
        }

    for (i = t; i < n; i++)
        if (arr[i] == "blue")
        {
            swap(arr, t, i);
            t++;
        }
}

void swap(std::string *arr, int t, int i)
{
    std::string temp = arr[t];
    arr[t] = arr[i];
    arr[i] = temp;
}