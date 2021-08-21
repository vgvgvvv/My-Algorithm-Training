#pragma once
#include <iostream>

struct BinaryTree {

    int val;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value)
        : val(value)
        , left(nullptr)
        , right(nullptr)
        {

        }

    BinaryTree(int value, BinaryTree* left, BinaryTree* right)
        : val(value)
        , left(left)
        , right(right)
        {

        }

    ~BinaryTree()
    {
        if(left) {
            delete left;
        }
        if(right) {
            delete right;
        }
    }
    
    void print_preorder() {
        std::cout << val << ", ";
        if(left){
            left->print_preorder();
        }else{
            std::cout << "null" << ", ";
        }
        if(right){
            right->print_preorder();
        }else{
            std::cout << "null" << ", ";
        }
    }
    
    void print_midorder() {
        if(left){
            left->print_midorder();
        }else{
            std::cout << "null" << ", ";
        }
        std::cout << val << ", ";
        if(right){
            right->print_midorder();
        }else{
            std::cout << "null" << ", ";
        }
    }

    void print_postorder() {
        if(left){
            left->print_postorder();
        }else{
            std::cout << "null" << ", ";
        }
        if(right){
            right->print_postorder();
        }else{
            std::cout << "null" << ", ";
        }
        std::cout << val << ", ";
    }
};