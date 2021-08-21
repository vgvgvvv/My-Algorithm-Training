#include "BinaryTree.h"

int main()
{
    BinaryTree tree(
        1, 
        new BinaryTree(2), 
        new BinaryTree(3));

    tree.print_preorder();
    std::cout << std::endl;
    tree.print_midorder();
    std::cout << std::endl;
    tree.print_postorder();
    return 0;    
}