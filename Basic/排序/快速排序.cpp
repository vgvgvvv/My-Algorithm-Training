#include "../Utility/Util.h"


// 单边循环法
int Partition(int* arr, int start, int end) {
    int pivot = arr[start];
    int mark = start;
    for(int i = start + 1; i <= end; i++){
        if(arr[i] < pivot){
            mark++;
            Exchange(arr, mark, i);
        }
    }
    Exchange(arr, start, mark);
    return mark;
}

// 双边循环
int Partition2(int* arr, int start, int end) {
    int pivot = arr[start];
    int mark = start;
    int left = start+1;
    int right = end;
    
    while(left < right) {
        while(left < right && arr[left] < pivot) {
            left++;
        }
        while(left < right && arr[right] > pivot) {
            right--;
        }
        Exchange(arr, left, right);
    }
    if(arr[left] > pivot) {
        left--;
    }
    Exchange(arr, start, left);
    return left;
}

void QuickSort(int* arr, int start, int end) {

    if(start >= end){
        return;
    }

    //int mid = Partition2(arr, start, end);
    int mid = Partition2(arr, start, end);

    QuickSort(arr, start, mid-1);
    QuickSort(arr, mid+1, end);

}

void QuickSort(int* arr, int length) {
    QuickSort(arr, 0, length-1);
}

int main() { 

    int a[] = {1, 3, 2, 5, 4};
    PRINT_ARR(a);

    QuickSort(a, LENGTHOF(a));

    PRINT_ARR(a);
    return 0;
}