#include <iostream>
#include "maxheap25.h"
using namespace std;

void useheaptosort(int nums[], int many)
{
    heap h(many);

    for (int i = 0; i < many; i++)
    {
        h.add(nums[i]);
    }
    for (int i = 0; i < many; i++)
    {
        nums[i] = h.remove();
    }
}

int main()
{
    int nums[] = {15, 20, 10, 5, 1, 2};
    int many = 6;

    useheaptosort(nums, many);
    cout << "Sorted list: ";
    for ( int i = 0; i < many; ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

}
