#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
            end = mid - 1;

        mid = start + (end - start) / 2;
    }
    return -1;
}

int main()
{
    int evenarr[6] = {4, 6, 10, 75, 96, 101};
    int oddarr[5] = {4, 66, 78, 114, 120};

    int evenindex = binarySearch(evenarr, 6, 96);
    cout << "Index of 96 is " << evenindex << endl;

    int oddindex = binarySearch(oddarr, 5, 114);
    cout << "Index of 114 is " << oddindex << endl;

    return 0;
}