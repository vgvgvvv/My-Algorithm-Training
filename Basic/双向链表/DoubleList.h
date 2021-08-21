#pragma once
#include <iostream>

struct DoubleListNode {
    int val;
    DoubleListNode* prev;
    DoubleListNode* next;

    DoubleListNode(int value) 
        : val(value)
        , prev(nullptr)
        , next(nullptr) {
    }
};

struct DoubleList {

    DoubleListNode* head;
    DoubleListNode* tail;

    void push_head(int value);
    void push_back(int value);
    int get(int index);
    void remove(int value);
    void remove_at(int index);
    void reverse();
    void print();
    void back_print();

    DoubleList() : head(nullptr), tail(nullptr) {
        head = new DoubleListNode(0);
        tail = new DoubleListNode(0);
        head->next = tail;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = head;
    }

    ~DoubleList() {
        auto current = head->next;
        while (current != tail)
        {
            auto deleteItem = current;
            current = current->next;
            delete deleteItem;
        }
        delete head;
        delete tail;
    }
};

void DoubleList::push_head(int value) {
    DoubleListNode* node = new DoubleListNode(value);
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}

void DoubleList::push_back(int value) {
    DoubleListNode* node = new DoubleListNode(value);
    node->next = tail;
    node->prev = tail->prev;
    tail->prev->next = node;
    tail->prev = node;
}

int DoubleList::get(int index) {
    auto current = head->next;
    int currentIndex = 0;

    while(index != currentIndex) {
        if(current == tail) {
            return -1;
        }
        current = current->next;
        currentIndex++;
    }
    if(current == tail) {
        return -1;
    }
    return current->val;
}

void DoubleList::remove(int value) {
   auto current = head;
   while(current->next != tail) {
       if(current->next->val == value) {
           auto removeItem = current->next;
           auto nextItem = removeItem->next;
           nextItem->prev = current;
           current->next = nextItem;
           delete removeItem;
           break;
       }
       current = current->next;
   }
}

void DoubleList::remove_at(int index) {
     auto current = head->next;
    int currentIndex = 0;

    while(index != currentIndex) {
        if(current == tail) {
            return;
        }
        current = current->next;
        currentIndex++;
    }
    if(current == tail) {
        return;
    }

    auto removeItem = current;
    auto prev = removeItem->prev;
    auto next = removeItem->next;
    prev->next = next;
    next->prev = prev;
    delete removeItem;
}

// 三指针反转
void DoubleList::reverse() {
    DoubleListNode* start = head->next;
    DoubleListNode* end = start->next;
    DoubleListNode* prev = end->next;

    start->next = tail;
    tail->prev = start;
    while(prev != tail) {
        end->next = start;
        start->prev = end;
        end->prev = prev;

        start = end;
        end = prev;
        prev = prev->next;

    }
    end->next = start;
    start->prev = end;
    end->prev = head;

    head->next = end;
    head->prev = nullptr;

}

void DoubleList::print() {
    auto current = head->next;
    std::cout << "list : ";
    while (current != tail)
    {
        std::cout << current->val << ",";
        current = current->next;
    }
    std::cout << std::endl;
}

void DoubleList::back_print() {
    auto current = tail->prev;
    std::cout << "list back : ";
    while(current != head) {
         std::cout << current->val << ",";
        current = current->prev;
    }
    std::cout << std::endl;
}