#include <iostream>
using namespace std;

int SearchHelper(int arr[], int size, int k, int start, int end)
{
    if (start < 0 || start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;
    if (arr[mid] == k)
    {
        return mid;
    }
    else if (arr[mid] < k)
    {
        return SearchHelper(arr, size, k, mid + 1, end);
    }
    else
    {
        return SearchHelper(arr, size, k, start, mid - 1);
    }
}

int SearchInSortedArray(int arr[], int size, int k)
{
    if (size <= 0)
    {
        return -1;
    }

    return SearchHelper(arr, size, k, 0, size - 1);
}

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

void SelectionSort(int arr[], int n)
{
    if (arr == nullptr)
    {
        return;
    }

    if (n <= 1)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        int min = arr[i];
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
    }
}

int main()
{
    int arr[] = { 2,5,3,7,9,11,10,1,0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << i << " ==> " << arr[i] << std::endl;
    }

    int loc = SearchInSortedArray(arr, n, 10);
    std::cout << "Element location is :" << loc << std::endl;

    loc = SearchInSortedArray(arr, n, 100);
    std::cout << "Element location is :" << loc << std::endl;
}