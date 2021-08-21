#pragma once
#include <iostream>

struct ListNode;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) { }

    void print() {
        std::cout << "nodes : ";
        auto current = this;
        std::cout << current->val << ",";
        while(current->next) {
            current = current->next;
            std::cout << current->val << ",";
        }
        std::cout << std::endl;
    }
};

struct List {
    ListNode* head;
    ListNode* tail;

    void push_head(int value);
    void push_back(int value);
    int get(int index);
    void remove(int value);
    void remove_at(int index);
    void reverse();
    void print();

    List() {
        head = new ListNode(0);
        tail = nullptr;
        head->next = tail;
    }

    ~List() {
        ListNode* start = head;
        while(start->next != tail) {
            auto current = start;
            start = start->next;
            delete current;
        }
        delete head;
    }
};

void List::push_head(int value) {
    ListNode* node = new ListNode(value);
    node->next = head->next;
    head->next = node;
}

void List::push_back(int value) {
     ListNode* node = new ListNode(value);
     ListNode* start = head;
     while(start->next != tail) {
         start = start->next;
     }
     node->next = tail;
     start->next = node;

}

int List::get(int index) {
    ListNode* current = head->next;
    int currentIndex = 0;
    while(index != currentIndex){
        if(current == tail){
            return -1;
        }
        current = current->next;
        currentIndex++;
    }
    if(current == tail){
        return -1;
    }
    return current->val;
}

void List::remove(int value) {
    ListNode* current = head;
    while(current->next != tail){
        if(current->next->val == value) {
            auto removeItem = current->next;
            auto nextItem = removeItem->next;
            current->next = nextItem;
            delete removeItem;
            break;
        }
        current = current->next;
    }
}

void List::remove_at(int index) {
    ListNode* current = head;
    int currentIndex = 0;
    while(index != currentIndex) {
        if(current->next == tail){
            return;
        }
        current = current->next;
        currentIndex++;
    }
    if(current->next == tail){
        return;
    }
    auto removeItem = current->next;
    auto nextItem = removeItem->next;
    current->next = nextItem;
    delete removeItem;
}


        
// 三指针反转
void List::reverse() {
    ListNode* start = head->next;
    ListNode* end = start->next;
    ListNode* prev = end->next;

    start->next = tail;
    while(prev != tail) {
        end->next = start;
        start = end;
        end = prev;
        prev = prev->next;
    }
    end->next = start;
    head->next = end;
}

void List::print() {
     std::cout << "list : ";
    ListNode* current = head;
    while(current->next != tail){
        std::cout << current->next->val << ",";
        current = current->next;
    }
    std::cout << std::endl;
}