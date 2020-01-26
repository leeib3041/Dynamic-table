
#ifndef UNTITLED_DYNAMICTABLE_H
#define UNTITLED_DYNAMICTABLE_H

#include <stdlib.h>

class DynamicTable {


public:
    DynamicTable(){
        //TODO: implement the constructor
        //modify the constructor for the dynamic table
        //when created the table should have space for one element
        //size and last should be set accordingly
    }

    ~DynamicTable(){
        //TODO: implement the destructor
        //when destroyed you should call explicitly the destructor for the array
    }

    void insert(int value); //TODO: implement the insert function


private:

    void resize(); //TODO: implement the resize function

    int* table; //array containing de facto the "list" of elements
    int size; //indicate the size of the array (how many spots it has)
    int last; //indicate the last element (how many spots are full)

};


#endif //UNTITLED_DYNAMICTABLE_H
