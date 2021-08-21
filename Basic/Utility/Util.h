#pragma once
#include <iostream>

#define LENGTHOF(arr) (sizeof(arr)/sizeof(arr[0]))

#define PRINT_ARR(arrName) PrintArr(arrName, LENGTHOF(arrName));

void PrintArr(int* arr, int length){
     for(int i = 0 ; i < length; i++){
        std::cout << arr[i] << ",";
    }
    std::cout << std::endl;
}

void Exchange(int* arr, int indexA, int indexB){
    int temp = arr[indexA];
    arr[indexA] = arr[indexB];
    arr[indexB] = temp; 
}