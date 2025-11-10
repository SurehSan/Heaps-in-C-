#include "heap_classes.h"

// default constructor
heap::heap()
{
    sz = 31;
    len = 0;
    arr = new int[sz+1];

}

//n is the size of the heap array
//parametized function
heap::heap( int n )
{
    sz = n;
    len = 0;
    arr = new int[sz+1];
}

// print the array
void heap::printA()
{
    int i;
    for (i = 1; i <= len; ++i)
        cout << setw(4) << arr[i] ;
    cout << endl;
}

void heap::add( int x )
{
    // do nothing if full
    len++;
    arr[len] = x;
    upheap(); //object variable

}

int heap::remove()
{
    // do nothing if empty
    if (isEmpty())
    {
        cout << "Heap is empty." << endl;
        return -1;
    }
    int rv;
    rv = arr[1];
    arr[1] = arr[len];
    len--;
    if (len > 0)
        downheap();
    return rv;
}

// start at item last, move it up until
//   heap property is restored
void heap::upheap()
{

    int i = len;
    while ( i > 1)
    {
        int parent = i / 2;
        if (arr[parent] < arr[i])
        {
            int parentnum = arr[parent];
            arr[parent] = arr[i];
            arr[i] = parentnum;
            i = parent;
        }
        else
            break;
    }
}

// start at item 1, move it down until
//   heap property is restored
// ** swap with larger child & repeat
void heap::downheap()
{
    int i = 1;
    int x = arr[i];
    while ( i*2 <= len )
    {
        int lchild = i * 2;
        int rchild = i * 2 + 1;
        int child = lchild;

        if (rchild <= len && arr[rchild] > arr[lchild])
            child = rchild;
        if (arr[child] <= x)
            break;
        arr[i] = arr[child];
        i = child;
    }
    arr[i] = x;
}

bool heap::isEmpty()
{
    if ( len == 0)
        return true;
    else
        return false;

}

bool heap::isFull()
{
    if ( len == sz)
        return true;
    else
        return false;
}
