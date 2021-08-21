#include "DoubleList.h"

int main()
{
    DoubleList list;
    list.push_back(5);
    list.push_back(4);
    list.push_back(3);
    list.push_back(2);
    list.push_back(1);
    list.print();
    list.back_print();

    list.push_head(6);
    list.print();
    list.back_print();

    list.remove(4);
    list.print();
    list.back_print();

    list.remove_at(2);
    list.print();
    list.back_print();

    list.reverse();
    list.print();
    list.back_print();

    std::cout << "value at 1 is "<< list.get(1) << std::endl;

    return 0;
}