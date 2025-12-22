#include <iostream>
#include <string>

using namespace std;

template <typename T, typename T2>
void print_arr(T *arr, int len)
{
    for (T2 i = 0; i < len; i++)
        cout << *(arr + i) << " ";

    cout << endl;
}

int main()
{
    int arr1[] = {5, 7, 8, 9, 1, -90, 6, 7};
    print_arr<int, int>(arr1, sizeof(arr1) / sizeof(arr1[0]));

    float arr2[] = {5.67f, 9.89f, 56.12f};
    print_arr<float, int>(arr2, sizeof(arr2) / sizeof(arr2[0]));

    return 0;
}
