#include <vector>
#include <iostream>

using namespace std;

void ModifyMaxHeap(vector<int>& arr, int index, int heapSize) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int largestIndex = index;
    if(left < heapSize && arr[left] > arr[largestIndex]) {
        largestIndex = left;
    }
    if(right < heapSize && arr[right] > arr[largestIndex]) {
        largestIndex = right;
    }
    if(largestIndex != index) {
        swap(arr[index], arr[largestIndex]);
        ModifyMaxHeap(arr, largestIndex, heapSize);
    }
}

void BuildMaxHeap(vector<int>& arr, int heapSize) {
    for(int i = heapSize / 2 ; i >= 0; i--) {
        ModifyMaxHeap(arr, i, heapSize);
    }
}


void ModifyMinHeap(vector<int>& arr, int index, int heapSize) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int minestIndex = index;
    if(left < heapSize && arr[left] < arr[minestIndex]) {
        minestIndex = left;
    }
    if(right < heapSize && arr[right] < arr[minestIndex]) {
        minestIndex = right;
    }
    if(index != minestIndex) {
        swap(arr[index], arr[minestIndex]);
        ModifyMinHeap(arr, minestIndex, heapSize);
    }
}

void BuildMinHeap(vector<int>& arr,  int heapSize) {
    for(int i = heapSize / 2; i >= 0; i --) {
        ModifyMinHeap(arr, i, heapSize);
    }
}

void HeapSortFromBig(vector<int>& arr) {
    int heapSize = arr.size();
    BuildMinHeap(arr, heapSize);
    for(int i = arr.size()-1; i >= 0; i --) {
        swap(arr[0],arr[i]);
        heapSize--;
        ModifyMinHeap(arr, 0, heapSize);
    }
}

void HeapSortFromSmall(vector<int>& arr) {
    int heapSize= arr.size();
    BuildMaxHeap(arr, heapSize);
    for(int i = arr.size() - 1; i >= 0; i --) {
        swap(arr[0], arr[i]);
        heapSize --;
        ModifyMaxHeap(arr, 0, heapSize);
    }
}

int main() {

    vector<int> arr = {5, 3, 1, 4, 2};

    for(int num : arr) {
        cout << num << ", ";
    }    
    cout << endl;

    HeapSortFromSmall(arr);

    for(int num : arr) {
        cout << num << ", ";
    }    
    cout << endl;

    return 0;
}