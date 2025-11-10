#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#include "heap_classes.h"

int main(int argc, char *argv[])
{
    heap h;
    int rv, x;

    ifstream fin(argv[1]);
    int cmd;


    while (fin >> cmd)
    {
        if (cmd == 0)
            break;
        if (cmd == 1)
        {
            fin >> x;
            h.add(x);
        }
        else if (cmd == -1)
        {
            rv = h.remove();
            cout << "Removed " << rv << "." << endl;
        }
        else if (cmd == 3)
        {
            h.printA();
        }

    }

    return 0;
}
