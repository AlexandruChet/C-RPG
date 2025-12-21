#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3};
    for_each(v.begin(), v.end(), [](int x)
        { cout << x << endl; });

    int c = scount(v.begin(), v.end(), 2);
    int even = count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });

    auto it = find(v.begin(), v.end(), 3);

    copy(v.begin(), v.end(), out.begin());

    return 0;
}
