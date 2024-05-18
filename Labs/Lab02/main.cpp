#include <iostream>

int noName(int n, int target, int limit)
{
    int *ptr = nullptr;
    for (int i = 0; i < n; i++)
    {
        ptr = new int(rand() % limit);
        if (*ptr == target)
            return i;
    }
    return -1;
}

int main()
{
    int cnt4, i, n, j, cnt2, cnt3;

    // a)
    for (cnt4 = 0, i = 1; i <= n; i *= 2)
        for (j = 1; j <= i; j++)
            cnt4++;

    // b)
    for (cnt2 = 0, i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
            cnt2++;

    // c)
    for (cnt3 = 0, i = 1; i <= n; i *= 2)
        for (j = 1; j <= n; j++)
            cnt3++;
}