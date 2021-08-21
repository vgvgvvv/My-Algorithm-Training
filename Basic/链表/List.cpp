#include <iostream>
#include "List.h"

int main()
{
    List list;
    list.push_back(5);
    list.push_back(4);
    list.push_back(3);
    list.push_back(2);
    list.push_back(1);
    list.print();

    list.push_head(6);
    list.print();

    list.remove(4);
    list.print();

    list.remove_at(2);
    list.print();

    list.reverse();
    list.print();

    return 0;
}