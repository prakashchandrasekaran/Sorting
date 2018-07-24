#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n)
{
    if (arr == nullptr)
    {
        return;
    }

    if (n <= 1)
    {
        return;
    }

    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int curr = arr[i];
        while (j >= 0 && arr[j] > curr)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

int main()
{
    int arr[] = { 2,5,3,7,9,11,10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << i << std::endl;
    }
}