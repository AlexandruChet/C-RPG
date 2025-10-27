#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(const vector<int> &array, int target)
{
    int left = 0;
    int right = array.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int mid_num = array[mid];

        if (mid_num == target)
            return mid;
        else if (target < mid_num)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> numbers = {5, 2, 8, 1, 9, 10, 89, 90, 56, 14};

    sort(numbers.begin(), numbers.end());

    int target = 14;
    int found_index = binary_search(numbers, target);

    if (found_index != -1)
        cout << "num " << target << " found in index " << found_index << endl;
    else
        cout << "num " << target << " not found " << endl;

    return 0;
}
