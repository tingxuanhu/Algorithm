// 快速排序
// 加入了三数取中的优化，没有加入当规模小于50时用插入排序的接口，可以面试时补充

#include <iostream>
using namespace std;

int selectPrior(int arr[], int l, int r)
{
    int mid = l + (r - l) >> 1;
    if (arr[l] > arr[mid])
    {
        std::swap(arr[l], arr[mid]);
    }
    if (arr[mid] > arr[r])
    {
        std::swap(arr[r], arr[mid]);
    }
    std::swap(arr[l], arr[mid]);
    return arr[l];
}

int Partition(int arr[], int L, int R)
{
    if (L == R) return L;
    // int val = arr[L];
    int val = selectPrior(arr, L, R);
    while (L < R) 
    {
        while (L < R && arr[R] >= val)
        {
            R--;
        }
        if (L < R)
        {
            arr[L] = arr[R];
        }
        while (L < R && arr[L] <= val)
        {
            L++;
        }
        if (L < R)
        {
            arr[R] = arr[L];
        }
    }
    arr[L] = val;
    return L;
}

void QuickSort(int arr[], int L, int R)
{
    if (L >= R) return;
    int pos = Partition(arr, L, R);
    QuickSort(arr, L, pos - 1);
    QuickSort(arr, pos + 1, R);
}

void QuickSort(int arr[], int size)
{
    return QuickSort(arr, 0, size - 1);
}


int main()
{
    int arr[] = {11, 99, 33 , 69, 77, 88, 55, 11, 33, 36, 39, 66, 44, 22};

    int size = static_cast<int>(sizeof(arr) / sizeof(arr[0]));

    QuickSort(arr, (size));
    for (auto a : arr)
    {
        cout << a << endl;
    }
}
