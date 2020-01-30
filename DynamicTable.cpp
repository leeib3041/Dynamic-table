
#include "DynamicTable.h"


void DynamicTable::insert(int value)
{
    //add a new element in the table
    if (last == size) resize();
    table[last] = value;
    last++;
}

void DynamicTable::resize()
{
    //resize the table when necessary
    int* newTable = new int[size*2];
    for (int i = 0; i < size; i++) newTable[i] = table[i];
    delete [] table;
    table = newTable;
    size = size*2;
}
